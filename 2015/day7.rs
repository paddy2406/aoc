use std::collections::HashMap;
use std::fs;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  let parsed_input = parse_input(input);
  let part_one_solution = part_one(parsed_input.clone());

  println!("Part One: {:?}", part_one_solution);
  println!("Part Two: {:?}", part_two(parsed_input, part_one_solution));
}

fn part_one(input: HashMap<String, String>) -> u16 {
  let mut cache: HashMap<String, u16> = HashMap::new();
  return get_wire_value(&mut cache, &input, "a".to_string());
}

fn part_two(input: HashMap<String, String>, part_one_solution: u16) -> u16 {
  let mut cache: HashMap<String, u16> = HashMap::new();
  cache.insert("b".to_string(), part_one_solution);
  return get_wire_value(&mut cache, &input, "a".to_string());
}

fn parse_input(input: String) -> HashMap<String, String> {
  return input
    .lines()
    .map(|l| l.split("->").map(|x| x.trim()).collect::<Vec<&str>>())
    .map(|x| (x[1].to_string(), x[0].to_string()))
    .collect::<HashMap<String, String>>();
}

fn get_wire_value(
  cache: &mut HashMap<String, u16>,
  circuit_layout: &HashMap<String, String>,
  wire: String,
) -> u16 {
  if let Ok(res) = wire.parse::<u16>() {
    return res;
  }
  if let Some(saved_value) = cache.get(&wire) {
    return *saved_value;
  }
  let mut res = 0;
  let peter = circuit_layout
    .get(&wire)
    .unwrap()
    .split_whitespace()
    .collect::<Vec<&str>>();
  match peter.len() {
    1 => {
      res = get_wire_value(cache, circuit_layout, peter[0].to_string());
    }
    2 => {
      res = !get_wire_value(cache, circuit_layout, peter[1].to_string());
    }
    3 => match peter[1] {
      "AND" => {
        res = get_wire_value(cache, circuit_layout, peter[0].to_string())
          & get_wire_value(cache, circuit_layout, peter[2].to_string());
      }
      "OR" => {
        res = get_wire_value(cache, circuit_layout, peter[0].to_string())
          | get_wire_value(cache, circuit_layout, peter[2].to_string());
      }
      "LSHIFT" => {
        res = get_wire_value(cache, circuit_layout, peter[0].to_string())
          << peter[2].parse::<u8>().unwrap();
      }
      "RSHIFT" => {
        res = get_wire_value(cache, circuit_layout, peter[0].to_string())
          >> peter[2].parse::<u8>().unwrap();
      }
      _ => {}
    },
    _ => {}
  }
  cache.insert(wire, res);
  return res;
}
