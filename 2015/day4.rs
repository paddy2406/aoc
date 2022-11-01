fn main() {
  let input = "bgvyzdsv";
  println!("Part One: {:?}", part_one(input));
  println!("Part Two: {:?}", part_two(input));
}

fn part_one(input: &str) -> i32 {
  let mut i = 1;
  loop {
    let peter = format!("{:x}", md5::compute(format!("{}{}", input, i)));
    if peter.starts_with("00000") {
      break;
    }
    i += 1;
  }
  return i;
}

fn part_two(input: &str) -> i32 {
  let mut i = 1;
  loop {
    let peter = format!("{:x}", md5::compute(format!("{}{}", input, i)));
    if peter.starts_with("000000") {
      break;
    }
    i += 1;
  }
  return i;
}
