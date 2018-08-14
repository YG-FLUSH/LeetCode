package main

import "fmt"

func strStr(haystack string, needle string) int {
	if needle == "" {
		return 0
	}
	var i = 0
	for i < len(haystack) {
		var j = 0
		var tmp_i = i
		for j < len(needle) {
			if tmp_i < len(haystack) && needle[j] == haystack[tmp_i] {
				j += 1
				tmp_i += 1
			} else {
				break
			}
		}
		if j == len(needle) {
			return i
		}
		i += 1
	}
	return -1
}

func main() {
	var haystack = "aa"
	var needle = "aaa"
	fmt.Println("index: ", strStr(haystack, needle))
}
