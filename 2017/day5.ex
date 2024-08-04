defmodule Main do
  use Application

  def start(_, _) do
    input = File.read!("input.txt") |> String.split("\n") |> Enum.map(&String.to_integer/1)

    IO.puts("Part one: #{Part_one.solve(input)}")
    IO.puts("Part two: #{Part_two.solve(input)}")

    Task.start(fn ->
      nil
    end)
  end
end

defmodule Part_one do
  def solve(list) do
    jump_trough_list(list, 0, 0)
  end

  def jump_trough_list(list, position, jumps_done)
      when position >= 0 and position < length(list) do
    jump_trough_list(
      List.update_at(list, position, &(&1 + 1)),
      position + Enum.at(list, position),
      jumps_done + 1
    )
  end

  def jump_trough_list(_list, _position, jumps_done) do
    jumps_done
  end
end

# orginally like Part_one. Switched to Map due to performance
# https://www.reddit.com/r/adventofcode/comments/7hngbn/comment/dqsfjjz/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
defmodule Part_two do
  def solve(list) do
    list
    |> Enum.with_index()
    |> Enum.reduce(%{}, fn {jump, i}, acc -> Map.put(acc, i, jump) end)
    |> jump_trough_list(0, 0)
  end

  def jump_trough_list(map, position, jumps_done)
      when position >= 0 and position < map_size(map) do
    jump_trough_list(
      Map.update!(map, position, fn x -> if x > 2, do: x - 1, else: x + 1 end),
      position + map[position],
      jumps_done + 1
    )
  end

  def jump_trough_list(_list, _position, jumps_done) do
    jumps_done
  end
end
