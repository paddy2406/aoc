defmodule Main do
  use Application

  def start(_, _) do
    input = 347_991

    IO.puts("Part one: #{Part_one.solve(input)}")
    IO.puts("Part two: #{Part_two.solve(input)}")

    Task.start(fn ->
      nil
    end)
  end
end

defmodule Position do
  defstruct x: 0, y: 0, steps_to_take: 1.0, steps_taken: 0, direction: {1, 0}

  @type t :: %__MODULE__{
          x: integer,
          y: integer,
          steps_to_take: float,
          steps_taken: integer,
          direction: {integer, integer}
        }
end

defmodule Common do
  def next_direction(x) do
    case x do
      {1, 0} -> {0, 1}
      {0, 1} -> {-1, 0}
      {-1, 0} -> {0, -1}
      {0, -1} -> {1, 0}
    end
  end

  @spec next_position(Position.t()) :: Position.t()
  def next_position(%Position{} = position) do
    if(Float.floor(position.steps_to_take) != position.steps_taken) do
      {steps_in_x, steps_in_y} = position.direction

      %Position{
        position
        | x: position.x + steps_in_x,
          y: position.y + steps_in_y,
          steps_taken: position.steps_taken + 1
      }
    else
      %Position{
        position
        | steps_taken: 0,
          steps_to_take: position.steps_to_take + 0.5,
          direction: Common.next_direction(position.direction)
      }
    end
  end
end

defmodule Part_one do
  @spec solve(pos_integer()) :: pos_integer()
  def solve(total_steps) do
    travel(%Position{}, total_steps - 1)
  end

  @spec travel(Position.t(), pos_integer()) :: pos_integer()
  def travel(%Position{} = position, total_steps) when total_steps > 0 do
    next = Common.next_position(position)

    if(next.steps_taken == 0) do
      travel(next, total_steps)
    else
      travel(next, total_steps - 1)
    end
  end

  @spec travel(Position.t(), 0) :: pos_integer()
  def travel(%Position{} = position, 0) do
    abs(position.x) + abs(position.y)
  end
end

defmodule Part_two do
  @offset 10

  @spec solve(pos_integer()) :: pos_integer()
  def solve(input) do
    matrix = List.duplicate(List.duplicate(0, @offset * 2 + 1), @offset * 2 + 1)
    matrix_with_start = matrix_write_value(matrix, 0, 0, 1)
    first_after_start = Common.next_position(%Position{})
    travel(first_after_start, matrix_with_start, input)
  end

  def travel(%Position{} = position, matrix, input) do
    sum = matrix_sum_neighbours(matrix, position.x, position.y)

    if(sum > input) do
      sum
    else
      next_position = Common.next_position(position)
      new_matrix = matrix_write_value(matrix, position.x, position.y, sum)
      travel(next_position, new_matrix, input)
    end
  end

  def matrix_sum_neighbours(matrix, x, y) do
    matrix_get_value(matrix, x - 1, y - 1) + matrix_get_value(matrix, x, y - 1) +
      matrix_get_value(matrix, x + 1, y - 1) + matrix_get_value(matrix, x - 1, y) +
      matrix_get_value(matrix, x + 1, y) + matrix_get_value(matrix, x - 1, y + 1) +
      matrix_get_value(matrix, x, y + 1) + matrix_get_value(matrix, x + 1, y + 1)
  end

  @spec matrix_get_value([[non_neg_integer()]], integer(), integer()) :: non_neg_integer()
  def matrix_get_value(matrix, x, y) do
    if(out_of_bounds(x) or out_of_bounds(y)) do
      0
    else
      Enum.at(Enum.at(matrix, y + @offset), x + @offset)
    end
  end

  @spec matrix_write_value([[non_neg_integer()]], integer(), integer(), integer()) :: [
          [non_neg_integer()]
        ]
  def matrix_write_value(list, x, y, value) do
    if(out_of_bounds(x) or out_of_bounds(y)) do
      list
    else
      list
      |> Enum.with_index()
      |> Enum.map(fn {elem, a} ->
        if(a == y + @offset) do
          elem
          |> Enum.with_index()
          |> Enum.map(fn {elem, b} ->
            if(b == x + @offset) do
              value
            else
              elem
            end
          end)
        else
          elem
        end
      end)
    end
  end

  @spec out_of_bounds(integer()) :: boolean()
  def out_of_bounds(a) do
    abs(a) > @offset
  end
end

# Cool solution to part 1 using streams
# https://github.com/amarraja/advent-of-code-17/blob/master/day03/day03.exs
defmodule Day03 do
  @input 347_991

  def part_1 do
    {x, y, v, _} =
      spiral_grid_stream() |> Stream.drop(@input - 1) |> Stream.take(1) |> Enum.to_list() |> hd

    IO.inspect(
      spiral_grid_stream()
      |> Stream.take(10)
      |> Enum.to_list()
    )

    diff = abs(x) + abs(y)
    "Steps for #{v} = #{diff}"
  end

  def part_2 do
    spiral_grid_stream_children()
    |> Stream.drop_while(fn {_x, _y, v, _} -> v <= @input end)
    |> Stream.take(5)
    |> Enum.to_list()
    |> hd
  end

  def directions do
    Stream.cycle([[:right, :up], [:left, :down]])
    |> Stream.zip(Stream.iterate(1, &(&1 + 1)))
    |> Stream.map(fn {directions, count} ->
      Enum.map(directions, fn d -> List.duplicate(d, count) end)
    end)
    |> Stream.flat_map(fn x -> x end)
    |> Stream.concat()
  end

  def spiral_grid_stream do
    dirs = Stream.concat([:none], directions())

    Stream.scan(dirs, {0, 0, 1, 1}, fn direction, {x, y, v, index} ->
      case direction do
        :right -> {x + 1, y, v + 1, index + 1}
        :up -> {x, y + 1, v + 1, index + 1}
        :left -> {x - 1, y, v + 1, index + 1}
        :down -> {x, y - 1, v + 1, index + 1}
        # only the first item
        :none -> {x, y, v, index}
      end
    end)
  end

  def spiral_grid_stream_children do
    {:ok, state} = Agent.start_link(fn -> %{} end)

    Stream.map(spiral_grid_stream(), fn {x, y, _v, index} = record ->
      {x, y, v, index} =
        case index do
          1 -> record
          _ -> {x, y, get_value(state, x, y), index}
        end

      Agent.update(state, fn map -> Map.put(map, {x, y}, v) end)
      {x, y, v, index}
    end)
  end

  def get_value(state, x, y) do
    Agent.get(state, fn m ->
      [
        {x - 1, y + 1},
        {x, y + 1},
        {x + 1, y + 1},
        {x - 1, y},
        {x + 1, y},
        {x - 1, y - 1},
        {x, y - 1},
        {x + 1, y - 1}
      ]
      |> Enum.map(fn k -> Map.get(m, k, 0) end)
      |> Enum.sum()
    end)
  end
end
