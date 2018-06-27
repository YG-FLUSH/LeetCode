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

        start_point = (0, 0)
        reflect_point = (p, q)
        # 每一次反射，角度相同
        while True:
            if reflect_point == (p, 0):
                return 2
            elif reflect_point == (0, p):
                return 0
            elif reflect_point == (p, p):
                return 1

            edge1 = reflect_point[0] - start_point[0]
            edge2 = reflect_point[1] - start_point[1]
            reflect_edge = p - edge2
            start_point = reflect_point
            reflect_point = start_point / reflect_point * (start_point - reflect_point)
            start_point = reflect_point


