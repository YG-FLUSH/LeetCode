package main

import "fmt"

func strStr(haystack string, needle string) int {
	if haystack == "" && needle != "" {
		return -1
	} else if haystack == "" && needle == "" {
		return 0
	} else if haystack != "" && needle == "" {
		return 0
	}

	for i := 0; i < len(haystack)-len(needle)+1; i++ {
		if haystack[i:i+len(needle)] == needle {
			return i
		}
	}
	return -1
}

func main() {
	haystack := "missippi"
	needle := "issip"
	fmt.Println("index:", strStr(haystack, needle))
}
