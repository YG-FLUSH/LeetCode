package main

import "fmt"

func islandPerimeter(grid [][]int) int {
	count := 0
	for i, row := range grid {
		for j, item := range row {
			if item == 1 {
				if i <= 0 || grid[i-1][j] == 0 {
					count += 1
				}
				if i >= len(grid)-1 || grid[i+1][j] == 0 {
					count += 1
				}
				if j <= 0 || grid[i][j-1] == 0 {
					count += 1
				}
				if j >= len(row)-1 || grid[i][j+1] == 0 {
					count += 1
				}
			}
		}
	}
	return count
}

func main() {
	grid := [][]int{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}
	fmt.Println("perimeter: ", islandPerimeter(grid))
}
