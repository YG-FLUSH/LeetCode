#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/19

class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for a in A:
            i = 0
            j = len(a) - 1
            while i <= j:
                if a[i] != a[j]:
                    a[i] = a[i] ^ a[j]
                    a[j] = a[i] ^ a[j]
                    a[i] = a[i] ^ a[j]

                if i == j:
                    a[i] = (a[i] + 1) % 2
                else:
                    a[i] = (a[i] + 1) % 2
                    a[j] = (a[j] + 1) % 2
                i += 1
                j -= 1
        return A



if __name__ == "__main__":
    A = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
    A = [[1,1,0],[1,0,1],[0,0,0]]
    print A
    print Solution().flipAndInvertImage(A)
