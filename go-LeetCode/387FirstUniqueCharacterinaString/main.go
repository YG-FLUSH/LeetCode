package main

import "fmt"

func firstUniqChar(s string) int {
	tmpMap := make(map[rune]int)
	for _, c := range s {
		tmpMap[c] += 1
	}
	for i, c := range s {
		count, ok := tmpMap[c]
		if ok && count == 1 {
			return i
		}
	}
	return -1
}

func main() {
	s := "leetcodel"
	fmt.Println("result: ", firstUniqChar(s))
}
