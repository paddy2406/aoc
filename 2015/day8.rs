use std::fs;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: String) -> i32 {
  let mut res = 0;
  for line in input.lines() {
    let mut escape = false;
    for c in line.chars() {
      match c {
        '\\' => { if escape { escape = false} else {escape = true; res += 1;}},
        'x' => {if escape { res += 2; escape = false }}
        _ => {escape = false}
      }
    }
    res += 2; 
  }
  return res;
}

fn part_two(input: String) -> i32 {
  let mut res = 0;
  for line in input.lines() {
    for c in line.chars() {
      match c {
        '\\' | '"' => { res += 1},
        _ => {}
      }
    }
    res += 2; 
  }
  return res;
}
