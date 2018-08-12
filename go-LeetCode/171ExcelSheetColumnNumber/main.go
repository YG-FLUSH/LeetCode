package main

import "fmt"
import "math"

func titleToNumber(s string) int {
	var result = 0
	for i := len(s); i > 0; i-- {
		// go 没有隐式转换 int 不能转成 float64
		// 只有相同类型的变量才能加减乘除操作, 类型不对得经过显示转换
		// rune 类型 是一种Unicode code point
		// https://programming.guide/go/rune.html
		result += int(math.Pow(26, float64(i-1))) * int(s[len(s)-i]-'A'+1)
	}
	return result
}

func main() {
	var input = "AB"
	fmt.Println("Input: ", input)
	fmt.Println("Output: ", titleToNumber(input))
}
