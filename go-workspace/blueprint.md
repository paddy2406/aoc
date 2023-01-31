```go

package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	file, err := os.ReadFile("input.txt")
	if err != nil {
		fmt.Print(err)
		return
	}
	input := string(file)
	fmt.Println("Part One:" + strconv.Itoa(part_one(input)))
	fmt.Println("Part Two:" + strconv.Itoa(part_two(input)))
}

func part_one(input string) int {
	return 1
}

func part_two(input string) int {
	return 1
}

```