package main

import "fmt"
import "sort"

func findContentChildren(g []int, s []int) int {
	// 对标准库用得不熟啊！！！
	sort.IntSlice(g).Sort()
	sort.IntSlice(s).Sort()
	var i = len(s) - 1
	var j = len(g) - 1
	var count = 0
	for i >= 0 && j >= 0 {
		fmt.Println(s[i], g[j])
		if s[i] >= g[j] {
			count++
			i--
			j--
		} else {
			j--
		}
	}
	return count
}

func main() {
	// var g = [...]int{1, 2, 3} cannot use g (type [...]int) as type []int in argument to findContentChildren
	// var g = [3]int{1, 2, 3} cannot use g (type [3]int) as type []int in argument to findContentChildren
	// go 数组，指定大小都算是不同类型的数据
	// go 分片，不指定大小的数组, 会根据实际情况分配空间
	// http://www.okyes.me/2016/05/31/go-array-slice-map.html

	var g = []int{10, 9, 8, 7}
	var s = []int{5, 6, 7, 8}
	var result = findContentChildren(g, s)
	fmt.Println("result: ", result)
}
