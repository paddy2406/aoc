defmodule Main do
  use Application

  def start(_, _) do
    input = File.read!("input.txt")

    IO.puts("Part one: #{Part_one.solve(input)}")
    IO.puts("Part two: #{Part_two.solve(input)}")

    Task.start(fn ->
      nil
    end)
  end
end

defmodule Part_one do
  def solve(_) do
    nil
  end
end

defmodule Part_two do
  def solve(_) do
    nil
  end
end
