package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
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
	temp := 0
	max := 0

	for _, line := range strings.Split(input, "\n") {
		if len(line) == 0 {
			if temp > max {
				max = temp
			}
			temp = 0
		} else {
			num, err := strconv.Atoi(line)
			if err == nil {
				temp = temp + num
			}
		}
	}
	return max
}

func part_two(input string) int {
	max3 := [3]int{0, 0, 0}
	temp := 0
	
	for _, line := range strings.Split(input, "\n") {
		if len(line) == 0 {
			lowest := 0
			for i, v := range max3 {
				if v < max3[lowest]{
					lowest = i
				}
			}
			
			if temp > max3[lowest] {
				max3[lowest] = temp
			}
			temp = 0
		} else {
			num, err := strconv.Atoi(line)
			if err == nil {
				temp = temp + num
			}
		}
	}
	
	sum := 0
	
	for _, value := range max3 {
		sum += value
	}

	return sum
}
