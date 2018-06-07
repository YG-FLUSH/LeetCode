#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/07

class Solution(object):

    def myAtoi(self, string):
        """
        :type string: str
        :rtype: int
        """
        meet_sign = False
        meet_char = False
        minus_sign = False
        num_buffer = []
        for s in string:
            if s == " ":
                # 数字后的空格
                if meet_char:
                    break
                continue

            if s in ("+", "-"):
                if meet_char:
                    break

                if meet_sign:
                    break

                meet_sign = True

                if s == "-":
                    minus_sign = True

                meet_char = True
                continue


            if s.isdigit():
                num_buffer.append(s)
            else:
                break
            meet_char = True

        if not num_buffer:
            return 0

        num_buffer.reverse()
        r_num = 0
        for i, num in enumerate(num_buffer):
            num = ord(num) - ord('0')
            r_num += ((10**i)*num)

        if minus_sign:
            r_num = 0-r_num

        if r_num > 2**31 - 1:
            return 2**31 - 1

        if r_num < -2**31:
            return -2**31
        return r_num

if __name__ == "__main__":
    string = "   0-1  "
    print Solution().myAtoi(string)

