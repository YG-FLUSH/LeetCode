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
        has_more_captital = False

        for c in word:
            if self.is_capital(c):
                if has_lowercase:
                    return False
                if not has_capital:
                    has_capital = True
                else:
                    has_more_captital = True
            else:
                if has_more_captital:
                    return False
                has_lowercase = True
        return True

    def is_capital(self, c):
        return 0 <= ord(c) - ord("A") < 26



if __name__ == "__main__":
    w = "USA"
    w = "FlaG"
    print Solution().detectCapitalUse(w)
