#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/08


class Solution(object):

    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i, j = 0, 0
        while True:
            if i == len(s) -1 and j == len(p) -1:
                return True

            if j > len(p)-1:
                return False

            if i > len(s)-1:
                return False

            s_char = s[i]
            p_char = p[j]

            print i, j
            print s_char, p_char

            # zero or more preceding element
            if p_char == "*":
                if j < 1:
                    j += 1
                    continue

                pp_char = p[j-1]
                if pp_char == ".":
                    pp_char = s[i-1]

                # 匹配0到n个pp_char
                while True:
                    if pp_char == s[i]:
                        i += 1
                        if i == len(s):
                            i -= 1
                            break
                        continue
                    else:
                        i += 1
                        break

                j += 1
                continue


            # 如果s_char 是 * . 如何处理?
            if p_char == s_char or p_char == ".":
                i += 1
                j += 1
                continue

            # p_char != s_char
            elif j < len(p) -1 and p[j+1] == "*":
                j += 1
                continue

            return False



if __name__ == "__main__":
    print Solution().isMatch("aa", "a")
    print Solution().isMatch("aa", "a*")
    print Solution().isMatch("ab", ".*")
    print Solution().isMatch("aab", "c*a*b")
