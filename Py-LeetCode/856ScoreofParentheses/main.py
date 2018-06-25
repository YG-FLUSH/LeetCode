#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/25


class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        if not S:
            return 0

        return self.run(S, 0, len(S)-1)

    def run(self, S, start, end):
        i = start
        l_count = 0
        r_count = 0
        result = 0
        while i <= end:
            if S[i] == "(":
                l_count += 1

            else:
                r_count += 1

            i += 1

            if l_count == r_count:
                if start + 1 >= start+l_count+r_count-1-1:
                    result = 1
                else:
                    result = 2 * self.run(S, start+1, start+l_count+r_count-1-1)
                if end > start+l_count+r_count:
                    result += self.run(S, start+l_count+r_count, end)
                return result
        return result



if __name__ == "__main__":
    S = "(()(()))"
    # S = "()()()"
    print Solution().scoreOfParentheses(S)
