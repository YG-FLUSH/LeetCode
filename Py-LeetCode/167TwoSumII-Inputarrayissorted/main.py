#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/27

class Solution(object):

    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i = 0
        while i < len(numbers):
            num = numbers[i]
            find_num = target - num
            end = len(numbers)
            begin = i + 1
            while begin < end:
                half = (begin + end)/2
                if numbers[half] == find_num:
                    return [i+1, half+1]
                elif find_num > numbers[half] :
                    begin = half + 1
                else:
                    end = half
            i += 1
        return []


if __name__ == "__main__":
    a = [2,3,4]
    t = 6
    print Solution().twoSum(a, t)
