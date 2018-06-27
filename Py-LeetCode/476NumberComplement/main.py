#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/26


class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        result = []
        for bit in bin(num)[2:]:
            if bit == "0":
                result.append("1")
            else:
                result.append("0")

        return int("".join(result), 2)



if __name__ == "__main__":
    print Solution().findComplement(5)
