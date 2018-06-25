#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/26


class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        result = []
        for i in range(left, right+1):
            if self.check_selfdividing(i):
                result.append(i)
        return result


    def check_selfdividing(self, num):
        num_str = str(num)
        for n in num_str:
            if int(n) == 0:
                return False
            elif num % int(n) != 0:
                return False
        return True

if __name__ == "__main__":
    print Solution().selfDividingNumbers(1, 22)

