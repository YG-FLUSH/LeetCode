#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/07/01

class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        left_c = -1
        right_c = -1
        result = []
        all_c_inx = []

        for i, s in enumerate(S):
            if s == C:
                all_c_inx.append(i)

        i = 0
        j = 0
        while i < len(S):
            if i < all_c_inx[j]:
                if j == 0:
                    result.append(all_c_inx[j] - i)
                else:
                    result.append(min(all_c_inx[j]-i, i-all_c_inx[j-1]))
            elif i == all_c_inx[j]:
                result.append(0)
                if j + 1 < len(all_c_inx):
                    j += 1
            else:
                result.append(i-all_c_inx[j])
            i += 1

        return result


if __name__ == "__main__":
    S = "aaba"
    C = "b"
    print Solution().shortestToChar(S, C)
