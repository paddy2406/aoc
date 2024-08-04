defmodule Main do
  use Application

  def start(_, _) do
    input =
      File.read!("input.txt")
      |> String.split("\n")
      |> Enum.map(fn line -> String.split(line, "\t") end)
      |> Enum.map(fn line -> Enum.map(line, fn x -> String.to_integer(x) end) end)

    IO.puts("Part one: #{Part_one.solve(input)}")
    IO.puts("Part two: #{Part_two.solve(input)}")

    Task.start(fn ->
      nil
    end)
  end
end

defmodule Part_one do
  def solve(input) do
    Enum.reduce(input, 0, fn line, acc -> acc + (Enum.max(line) - Enum.min(line)) end)
  end
end

defmodule Part_two do
  def solve(input) do
    Enum.reduce(input, 0, fn line, acc -> acc + divison_rec(Enum.sort(line, :desc)) end)
  end

  def divison_rec([head | tail]) do
    peter = Enum.find(tail, fn x -> rem(head, x) == 0 end)

    if(peter !== nil) do
      div(head, peter)
    else
      divison_rec(tail)
    end
  end
end
