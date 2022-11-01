use std::fs;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: String) -> i32 {
  let mut sum = 0;
  for present in input.split("\n") {
    let mut dimensions: Vec<i32> = present
      .split("x")
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    sum += 2 * dimensions[0] * dimensions[1]
      + 2 * dimensions[1] * dimensions[2]
      + 2 * dimensions[0] * dimensions[2];
    dimensions.sort();
    sum += dimensions[0] * dimensions[1];
  }

  return sum;
}

fn part_two(input: String) -> i32 {
  let mut sum = 0;
  for present in input.split("\n") {
    let mut dimensions: Vec<i32> = present
      .split("x")
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    dimensions.sort();
    sum += 2 * dimensions[0] + 2 * dimensions[1];
    sum += dimensions[0] * dimensions[1] * dimensions[2];
  }
  return sum;
}
