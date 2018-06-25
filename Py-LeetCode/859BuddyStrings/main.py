#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/24


class Solution(object):
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False

        i = 0
        diff_char_index = -1
        finish_check = False
        while i < len(A):
            if A[i] != B[i]:
                if diff_char_index == -1:
                    diff_char_index = i
                else:
                    if finish_check:
                        return False

                    if A[i] == B[diff_char_index] and A[diff_char_index] == B[i]:
                        finish_check = True
                    else:
                        return False
            i += 1

        if finish_check:
            return True

        duplicate_char_map = {}
        for a in A:
            if a not in duplicate_char_map:
                duplicate_char_map[a] = 0
            duplicate_char_map[a] += 1

        for value in duplicate_char_map.values():
            if value >= 2:
                return True
        return False


if __name__ == "__main__":
    A = "abcaaa"
    B = "bcaaaa"
    print Solution().buddyStrings(A, B)
