#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/22

class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        x = list(bin(x).replace("0b", ""))
        x.reverse()
        y = list(bin(y).replace("0b", ""))
        y.reverse()
        i = 0
        distance = 0
        max_len = max(len(x), len(y))
        while i < max_len:
            if i >= len(y):
                p_y = "0"
            else:
                p_y = y[i]
            if i >= len(x):
                p_x = "0"
            else:
                p_x = x[i]

            if p_x != p_y:
                distance += 1
            i += 1
        return distance


if __name__ == "__main__":
    print Solution().hammingDistance(4, 14)
