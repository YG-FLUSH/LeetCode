#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/25

class Solution(object):
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        x, y = 0, 0
        b = 0
        a = float(q) / p
        while True:
            if round(y, 5) == p and round(x, 5) == 0:
                return 2
            elif round(y, 5) == p and round(x, 5) == p:
                return 1
            elif round(y, 5) == 0 and round(x, 5) == p:
                return 0

            b = y - a * x
            x, y = self.find_reflection_point(p, a, b, x, y)
            # 反射斜率不变
            # 偶数次反射斜率取负
            a = -a


    def find_reflection_point(self, p, a, b, origin_x, origin_y):
        if origin_x in (0, p):
            x = p if origin_x == 0 else 0
            y = self._cal_y(p, a, b, x)
            if y is not None:
                return (x, y)
            for y in (0, p):
                x = self._cal_x(p, a, b, y)
                if x is not None:
                    return (x, y)

        if origin_y in (0, p):
            y = p if origin_y == 0 else 0
            x = self._cal_x(p, a, b, y)
            if x is not None:
                return (x, y)

            for x in (0, p):
                y = self._cal_y(p, a, b, x)
                if y is not None:
                    return (x, y)

        raise Exception(" not found reflection point")

    def _cal_y(self, p, a, b, x):
        y = a * x + b
        if 0 <= y <= p:
            return y
        return None

    def _cal_x(self, p, a, b, y):
        x = (y-b) / a
        if 0 <= x <= p:
            return x
        return None


if __name__ == "__main__":
    p = 20
    q = p / 3.0
    print Solution().mirrorReflection(p, q)

