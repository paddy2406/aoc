use std::fs;
use regex::Regex;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();

  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: String) -> usize {
  let escape_backslash_quote_regex = Regex::new(r#"(?:\\")|(?:\\\\)"#).unwrap();
  let hex_regex = Regex::new(r#"\\x"#).unwrap();
  let mut res = 0;
  for line in input.lines() {
    println!("{:?}",line.chars());
    
    res +=  line.chars().count() - 2 - escape_backslash_quote_regex.find_iter(line).count() - 3 * hex_regex.find_iter(line).count();
  }
 
  return res;
}

fn part_two(input: String) -> i32 {
  return 1;
}
