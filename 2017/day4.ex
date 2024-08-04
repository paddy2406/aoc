defmodule Main do
  use Application

  def start(_, _) do
    input =
      File.read!("input.txt") |> String.split("\n") |> Enum.map(&String.split(&1, " "))

    IO.puts("Part one: #{Part_one.solve(input)}")
    IO.puts("Part one_v2: #{Part_one_v2.solve(input)}")
    IO.puts("Part two: #{Part_two.solve(input)}")

    Task.start(fn ->
      nil
    end)
  end
end

defmodule Part_one do
  def solve(input) do
    input
    |> Enum.map(&is_passphrase_valid(&1))
    |> Enum.reduce(0, &(&1 + &2))
  end

  def is_passphrase_valid([head | tail]) do
    if(Enum.find(tail, &(&1 == head)) == nil) do
      is_passphrase_valid(tail)
    else
      0
    end
  end

  def is_passphrase_valid([]) do
    1
  end
end

# using built-in functions Enum.uniq/1 and Enum.count/2
defmodule Part_one_v2 do
  def solve(input) do
    input
    |> Enum.map(&(length(&1) == length(Enum.uniq(&1))))
    |> Enum.count(& &1)
  end
end

defmodule Part_two do
  def solve(input) do
    input
    |> Enum.map(&is_passphrase_valid(&1))
    |> Enum.count(& &1)
  end

  def is_passphrase_valid([head | tail]) do
    if(Enum.find(tail, &are_anagrams(&1, head))) do
      false
    else
      is_passphrase_valid(tail)
    end
  end

  def is_passphrase_valid([]) do
    true
  end

  def are_anagrams(a, b) do
    collect_letters(a) == collect_letters(b)
  end

  def collect_letters(word) do
    word
    |> String.graphemes()
    |> Enum.reduce(%{}, fn x, acc -> Map.update(acc, x, 1, &(&1 + 1)) end)
  end
end
