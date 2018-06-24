#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/24
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return sum(nums[::2])
