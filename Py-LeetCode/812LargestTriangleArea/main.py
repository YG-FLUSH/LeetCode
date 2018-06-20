#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/20


class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        corner1 = 0
        max_area = 0

        while corner1 < len(points) - 2:
            corner2 = corner1 + 1
            while corner2 < len(points) - 1:
                corner3 = corner2 + 1
                while corner3 < len(points):
                    area = self.cal_area(points[corner1], points[corner2], points[corner3])
                    if max_area < area:
                        max_area = area

                    corner3 += 1
                corner2 += 1
            corner1 += 1
        return max_area

    def cal_area(self, point1, point2, point3):
        x1 = point1[0]
        x2 = point2[0]
        x3 = point3[0]
        y1 = point1[1]
        y2 = point2[1]
        y3 = point3[1]
        return abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2) / 2.0



if __name__ == "__main__":
    # points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    points = [[2,5],[7,7],[10,8],[10,10],[1,1]]
    print Solution().largestTriangleArea(points)



