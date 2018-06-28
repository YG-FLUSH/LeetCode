#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/28


class Solution(object):

    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_count = 0
        _tmp = 0
        for num in nums:
            if num == 1:
                _tmp += 1
            else:
                if max_count < _tmp:
                    max_count = _tmp
                _tmp = 0
        if max_count < _tmp:
            max_count = _tmp
        return max_count


if __name__ == "__main__":
    nums = [1,1,0,1,1,1]
    print Solution().findMaxConsecutiveOnes(nums)
