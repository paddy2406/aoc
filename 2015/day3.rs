use std::fs;
use std::collections::HashMap;

#[derive(Clone, Copy, Eq, PartialEq, Hash)]
struct Position {
    x: i32,
    y: i32,
}

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: String) -> usize {
  let mut current_position = Position { x: 0, y: 0 };
  let mut visited = vec![current_position];

  for c in input.chars() {
      match c {
          '>' => current_position.x += 1,
          '<' => current_position.x -= 1,
          '^' => current_position.y += 1,
          'v' => current_position.y -= 1,
          _ => {}
      }
      let b = visited
          .iter()
          .position(|p| p.x == current_position.x && p.y == current_position.y);
      match b {
          Some(_x) => {},
          None => visited.push(current_position),
      }
  }
  return visited.len()
}

fn part_two(input: String) -> usize {
  let mut santa_position = Position { x: 0, y: 0 };
  let mut robo_position = Position { x: 0, y: 0 };
  let mut visited = HashMap::new(); // Vector (280ms) => Hashmap (8ms)
  let mut odd = true;

  visited.insert(santa_position, true);

  for c in input.chars() {
      let actor_position;
      match odd {
          true => actor_position = &mut santa_position,
          false => actor_position = &mut robo_position,
      }
      odd = !odd;
      match c {
          '>' => actor_position.x += 1,
          '<' => actor_position.x -= 1,
          '^' => actor_position.y += 1,
          'v' => actor_position.y -= 1,
          _ => {}
      }
      if !visited.contains_key(actor_position){
          visited.insert(*actor_position, true);
      }
  }
  return visited.len();
}

