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
        # map记录每一次的数字和索引
        # 因为升序，后面遇到的数字返回来查第一个数
        # 这样就不用回溯二分查找
        d = {}
        for i, num in enumerate(numbers):
            before_num = target - num
            if before_num not in d:
                d[num] = i
            else:
                return [d[before_num]+1, i+1]


if __name__ == "__main__":
    a = [2,3,4]
    t = 6
    print Solution().twoSum(a, t)
