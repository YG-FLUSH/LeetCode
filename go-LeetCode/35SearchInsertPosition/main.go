package main

import "fmt"

func searchInsert(nums []int, target int) int {
	for i, num := range nums {
		if num >= target {
			return i
		}
	}
	return len(nums)
}

func main() {
	var nums = []int{1, 3, 5, 6}
	var target = 2
	var inx = searchInsert(nums, target)
	fmt.Println("index: ", inx)
}
