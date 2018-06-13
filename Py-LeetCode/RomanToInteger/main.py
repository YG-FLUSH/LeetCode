#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/13


class Solution(object):
    # 快速替换
    # I             1
    # V             5
    # X             10
    # s/\(\w\) *\(\d*\)/"\1": \2,/g

    roman_map = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
    }
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        r = 0
        for i in range(len(s)):
            n = self.roman_map[s[i]]
            if i < len(s)-1:
                nn = self.roman_map[s[i+1]]
                if n < nn:
                    r -= n
                    continue
            r += n
        return r

if __name__ == "__main__":
    s = "IV"
    # s = "XXVII"
    s = "XXIV"
    # s = "CD"
    print Solution().romanToInt(s)

