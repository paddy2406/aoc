use std::fs;

fn main() {
  let input = fs::read_to_string("input.txt").unwrap();
  println!("Part One: {:?}", part_one(input.clone()));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: String) -> i32 {
  let mut nice_strings = 0;
  for line in input.split("\n") {
    let mut vowels = 0;
    let mut twice = false;
    let mut last_letter = '0';
    let mut bad_word = false;
    for c in line.chars() {
      if let Some(_) = "aeiou".find(c) {
        vowels += 1;
      }
      if c == last_letter {
        twice = true;
      }
      if (last_letter == 'a' && c == 'b')
        || (last_letter == 'c' && c == 'd')
        || (last_letter == 'p' && c == 'q')
        || (last_letter == 'x' && c == 'y')
      {
        bad_word = true;
      }
      last_letter = c;
    }
    if vowels >= 3 && twice && !bad_word {
      nice_strings += 1;
    }
  }
  return nice_strings;
}

fn part_two(input: String) -> i32 {
  let mut nice_strings = 0;
  for line in input.split("\n") {
    let mut double_sep = false;
    let mut two_pairs = false;
    let mut last_letter = '0';
    let mut second_last_letter = '0';
    let mut list_of_pairs: Vec<(char, char)> = vec![];
    for c in line.chars() {
      if last_letter != '0' {
        list_of_pairs.push((last_letter, c))
      }
      if second_last_letter == c {
        double_sep = true;
      }
      second_last_letter = last_letter;
      last_letter = c;
    }
    for (i, pair) in list_of_pairs.iter().enumerate() {
      for y in i..list_of_pairs.len() {
        if list_of_pairs[y] == *pair && (y as i32 - i as i32).abs() > 1 {
          two_pairs = true;
        }
      }
    }
    if double_sep && two_pairs {
      nice_strings += 1;
    }
  }
  return nice_strings;
}
