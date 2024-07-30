defmodule Both_parts do
  def solve(list, shift) do
    # Compare the list to a list that is shifted to the right
    compare(list, Enum.take(list, -shift) ++ Enum.take(list, length(list) - shift), 0)
  end

  def compare([head1 | tail1], [head2 | tail2], acc) do
    if(head1 == head2) do
      compare(tail1, tail2, acc + head1)
    else
      compare(tail1, tail2, acc)
    end
  end

  def compare([], [], acc) do
    acc
  end
end

input = File.read!("input.txt")

list_of_numbers = Enum.map(String.graphemes(input), fn x -> String.to_integer(x) end)

IO.puts("Part one: #{Both_parts.solve(list_of_numbers, 1)}")
IO.puts("Part two: #{Both_parts.solve(list_of_numbers, div(length(list_of_numbers), 2))}")
