#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/22

class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_island_area = 0
        tmp_island_area = 0
        i = 0
        max_island_points = []
        while i < len(grid):
            line = grid[i]
            j = 0
            while j < len(line):
                if max_island_points:
                    check_i, check_j = max_island_points.pop()
                    check_points = []
                    if check_i > 0:
                        check_points.append((check_i-1, check_j))

                    if check_i < len(grid)-1:
                        check_points.append((check_i+1, check_j))

                    if check_j > 0:
                        check_points.append((check_i, check_j-1))

                    if check_j < len(line)-1:
                        check_points.append((check_i, check_j+1))

                else:
                    check_points = [(i, j)]

                for point in check_points:
                    if grid[point[0]][point[1]] == 1:
                        tmp_island_area += 1
                        max_island_points.append(point)
                        # 避免重复计算
                        grid[point[0]][point[1]] = -1
                if not max_island_points:
                    if max_island_area < tmp_island_area:
                        max_island_area = tmp_island_area
                    tmp_island_area = 0
                    while j < len(line) and grid[i][j] in (0, -1):
                        j += 1
            i += 1
        return max_island_area



if __name__ == "__main__":
    a = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
         [0,0,0,0,0,0,0,1,1,1,0,0,0],
         [0,1,1,0,1,0,0,0,0,0,0,0,0],
         [0,1,0,0,1,1,0,0,1,0,1,0,0],
         [0,1,0,0,1,1,0,0,1,1,1,0,0],
         [0,0,0,0,0,0,0,0,0,0,1,0,0],
         [0,0,0,0,0,0,0,1,1,1,0,0,0],
         [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    a = [[1,1,0,0,0],
         [1,1,0,0,0],
         [0,0,0,1,1],
         [0,0,0,1,1]]
    print Solution().maxAreaOfIsland(a)

