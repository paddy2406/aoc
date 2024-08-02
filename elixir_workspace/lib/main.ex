defmodule Main do
  use Application

  def start(_, _) do
    IO.puts("HEllo World")

    Task.start(fn ->
      nil
    end)
  end
end

defmodule Position do
  defstruct vertical: 0, horizontal: 0
end

defmodule Part_one do
  def solve(input) do
    nil
  end
end

defmodule Part_two do
  def solve(input) do
    nil
  end
end

input = 347_991

IO.puts("Part one: #{Part_one.solve(input)}")
IO.puts("Part two: #{Part_two.solve(peter)}")
