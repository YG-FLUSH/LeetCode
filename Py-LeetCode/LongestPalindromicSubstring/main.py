#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/05

class Solution(object):

    def longestPalindrome(self, s):
        if not s:
            return ""

        s_len = len(s)
        if s_len == 1:
            return s

        i = 0
        max_len = 1
        start = 0
        while i < s_len:

            if s_len - i <= max_len/2:
                break

            r = l = i
            # 略过重复的, 向左右两边扩展
            while r < s_len -1 and s[r] == s[r+1]:
                r += 1

            i = r + 1
            while l > 0 and r < s_len -1 and s[l-1] == s[r+1]:
                l -= 1
                r += 1

            new_len = r - l + 1
            if new_len > max_len:
                max_len = new_len
                start = l
        return s[start:start+max_len]

if __name__ == "__main__":
    s = "babad"
    print Solution().longestPalindrome(s)
    s = "cbbd"
    print Solution().longestPalindrome(s)
