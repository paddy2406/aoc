use regex::Regex;
use std::fs;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: String) -> i32 {
  let re = Regex::new(r"(on|off|toggle) (\d+),(\d+) through (\d+),(\d+)").unwrap();
  let mut matrix = vec![false; 1000000];
  for line in input.split("\n") {
    let caps = re.captures(line).unwrap();

    let case = caps.get(1).unwrap().as_str();
    let x1 = caps.get(2).unwrap().as_str().parse::<i32>().unwrap();
    let y1 = caps.get(3).unwrap().as_str().parse::<i32>().unwrap();
    let x2 = caps.get(4).unwrap().as_str().parse::<i32>().unwrap();
    let y2 = caps.get(5).unwrap().as_str().parse::<i32>().unwrap();
    for i in y1..(y2 + 1) {
      for j in x1..(x2 + 1) {
        let index = ((i * 1000) + j) as usize;
        match case {
          "toggle" => matrix[index] = !matrix[index],
          "on" => matrix[index] = true,
          "off" => matrix[index] = false,
          _ => {}
        }
      }
    }
  }
  let mut sum = 0;
  for e in matrix {
    if e {
      sum += 1
    }
  }
  return sum;
}

fn part_two(input: String) -> i32{
  let re = Regex::new(r"(on|off|toggle) (\d+),(\d+) through (\d+),(\d+)").unwrap();
  let mut matrix = vec![0; 1000000];
  for line in input.split("\n") {
    let caps = re.captures(line).unwrap();

    let case = caps.get(1).unwrap().as_str();
    let x1 = caps.get(2).unwrap().as_str().parse::<i32>().unwrap();
    let y1 = caps.get(3).unwrap().as_str().parse::<i32>().unwrap();
    let x2 = caps.get(4).unwrap().as_str().parse::<i32>().unwrap();
    let y2 = caps.get(5).unwrap().as_str().parse::<i32>().unwrap();
    for i in y1..(y2 + 1) {
      for j in x1..(x2 + 1) {
        let index = ((i * 1000) + j) as usize;
        match case {
          "toggle" => matrix[index] += 2,
          "on" => matrix[index] += 1,
          "off" => {
            if matrix[index] > 0 {
              matrix[index] -= 1
            }
          }
          _ => {}
        }
      }
    }
  }
  let mut sum = 0;
  for e in matrix {
    sum += e
  }
  return sum;
}
