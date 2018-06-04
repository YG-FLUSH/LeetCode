#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/04

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return ""
        r_str = ""
        i, j = 0, len(s)
        while i < len(s):
            while j > i:
                check_i, check_j = i, j
                is_palindrome = True
                while check_i < check_j:
                    if s[check_i] != s[check_j-1]:
                        is_palindrome = False
                        break
                    check_i += 1
                    check_j -= 1
                if is_palindrome and len(r_str) < j - i:
                    r_str = s[i:j]
                j -= 1

            i += 1
            j = len(s)
        return r_str


if __name__ == "__main__":
    s = "cbbd"
    print Solution().longestPalindrome(s)
