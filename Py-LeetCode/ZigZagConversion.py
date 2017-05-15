#!/usr/bin/env python
#  coding=utf-8
#  Author:  Yoge
#  Time:  2016/10/14
"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

思路：
"""

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        _ls = [""] * numRows

        _len_line_zigzag = (2*numRows - 2)

        for i, val in enumerate(s):
            r = i % _len_line_zigzag
            if r > numRows - 1:
                r = _len_line_zigzag - r
            _ls[r]+=val
        return "".join(_ls)



if __name__ == "__main__":
    s = "abcdefghi"
    n = 5
    print Solution().convert(s, n)
