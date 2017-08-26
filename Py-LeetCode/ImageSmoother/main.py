#!/usr/bin/env python
#   coding=utf-8
#   Author: Yoge
#   Time: 2017/0826

import copy

class Solution(object):

    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        if not M:
            return []
        if not M[0]:
            return [[]]

        result = copy.deepcopy(M)
        for i, row in enumerate(M):
            for j, col in enumerate(row):
                result[i][j] = self.get_adjacent_piont_average(M, i, j)
        return result


    def get_adjacent_piont_average(self, M, row_num, col_num):
        row_ls = [row_num - 1, row_num, row_num + 1]
        col_ls = [col_num - 1, col_num, col_num + 1]
        _sum = 0
        _count = 0
        for row in row_ls:
            if row < 0 or row >= len(M):
                continue
            for col in col_ls:
                if col < 0 or col >= len(M[0]):
                    continue
                _sum += M[row][col]
                _count += 1
        return _sum / _count


if __name__ == "__main__":
    test_ls = [[1,1,1],
               [1,0,1],
               [1,1,1]]
    print Solution().imageSmoother(test_ls)
