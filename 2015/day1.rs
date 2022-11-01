use std::fs;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input).unwrap());
}

fn part_one(input: String) -> i32 {
  let mut floor = 0;

  for c in input.chars() {
    if c == '(' {
      floor += 1;
    } else if c == ')' {
      floor -= 1;
    }
  }
  return floor;
}

fn part_two(input: String) -> Option<usize> {
  let mut floor = 0;
  for (i, c) in input.char_indices() {
    if c == '(' {
      floor += 1;
    } else if c == ')' {
      floor -= 1;
    }
    if floor == -1 {
      return Some(i + 1);
    }
  }
  None
}

