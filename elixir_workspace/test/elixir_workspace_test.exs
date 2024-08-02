defmodule ElixirWorkspaceTest do
  use ExUnit.Case
  doctest ElixirWorkspace

  test "greets the world" do
    assert ElixirWorkspace.hello() == :world
  end
end
