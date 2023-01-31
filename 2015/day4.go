package main

import (
	"crypto/md5"
	"encoding/hex"
	"fmt"
	"strconv"
	"strings"
	"time"
)

func main() {
	input := "bgvyzdsv"
	fmt.Println("Part One:" + strconv.Itoa(part_one(input)))
	fmt.Println("Part Two:" + strconv.Itoa(part_two(input)))

	start := time.Now()
	fmt.Println("seven zeros:" + strconv.Itoa(seven_zeros(input)))
	duration := time.Since(start)
	fmt.Println(duration)

}

func part_one(input string) int {
	i := 1
	for {
		peter := md5.Sum([]byte(input + strconv.Itoa(i)))
		peter2 := hex.EncodeToString(peter[:])
		if strings.HasPrefix(peter2, "00000") {
			fmt.Println(peter)
			break
		}
		i++
	}
	return i
}

func part_two(input string) int {
	i := 1
	for {
		peter := md5.Sum([]byte(input + strconv.Itoa(i)))
		peter2 := hex.EncodeToString(peter[:])
		if strings.HasPrefix(peter2, "000000") {
			fmt.Println(peter)
			break
		}
		i++
	}
	return i
}

func seven_zeros(input string) int {
	lock := make(chan int, 20)
	result_channel := make(chan int)
	i := 0
	for {
		select {
		case lock <- 1:
			go hash(input, i*10_000_000, result_channel, lock)
			i++
		default:
			select {
			case peter := <-result_channel:
				return peter
			default:
			}
		}
	}
}

func hash(input string, start int, out chan<- int, lock <-chan int) {
	for i := start; i < start+10_000_000; i++ {
		peter := md5.Sum([]byte(input + strconv.Itoa(i)))
		if peter[0] == 0 && peter[1] == 0 && peter[2] == 0 && peter[3] < 16 {
			fmt.Println(peter[:4])
			out <- i
		}
	}
	<-lock
}

// strings.HasPrefix(peter2, "0000000")
//peter2 := hex.EncodeToString(peter[:4])
