#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/23

class Solution(object):

    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        s = i = 1
        count = 0
        while s <= N:
            n = N / i
            r = N % i
            print n, i
            if (n - i / 2) >= 0:
                if r == 0:
                    if n == N:
                        count += 1
                        self.print_num_list(n, i)
                    elif N % 2 == 1:
                        count += 1
                        self.print_num_list(n, i)

                elif r * 2 == i:
                    count += 1
                    self.print_num_list(n, i)

            i += 1
            s += i
        return count

    def print_num_list(self, n, i):
        print n, i
        half = i / 2
        buf = range(n - half, n + half+1)
        print buf


if __name__ == "__main__":
    print Solution().consecutiveNumbersSum(6)
