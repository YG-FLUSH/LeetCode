#!/usr/bin/env python
#  coding=utf-8
#  Author:  Yoge
#  Time:  2016/10/18
"""
Implement pow(x, n).

built-in solution x**n is slower than the flowing
"""

class Solution(object):

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1

        if n < 0:
            n = -n
            x = 1/x

        return x * self.myPow(x*x, n/2) if n % 2 == 1 else self.myPow(x*x, n/2)



