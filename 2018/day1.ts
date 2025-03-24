import fs from "node:fs"

const input = fs
  .readFileSync("input.txt", "utf-8")
  .split("\n")
  .map((x) => +x)

console.log(partOne(input))
console.log(partTwo(input))

function partOne(input: number[]): number {
  return input.reduce((a, b) => a + b, 0)
}

function partTwo(input: number[]): number {
  const frequenciesSeen = new Map<number, boolean>()
  let currentfrequeny = 0
  while (true) {
    for (const item of input) {
      if (frequenciesSeen.has(currentfrequeny)) {
        return currentfrequeny
      }
      frequenciesSeen.set(currentfrequeny, true)
      currentfrequeny += item
    }
  }
}
