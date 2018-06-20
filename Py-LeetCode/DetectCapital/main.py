#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/19

class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        has_capital = False
        has_lowercase = False
        for c in word:
            if self.is_capital(c):
                has_capital = True
            else:
                has_lowercase = True


    def is_capital(self, c):
        return 0 <= ord(c) - ord("A") < 26



if __name__ == "__main__":
    w = "USA"
    Solution().detectCapitalUse(w)
