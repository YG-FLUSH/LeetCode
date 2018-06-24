#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/23


class Solution(object):

    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        i = 0
        large_group = []
        count = 1
        start = 0
        while i < len(S)-1:
            if S[i] == S[i+1]:
                if count == 1:
                    start = i
                count += 1
            else:
                if count >= 3:
                    large_group.append([start, i])
                start = 0
                count = 1
            i += 1

        if count >= 3:
            large_group.append([start, i])

        return large_group


if __name__ == "__main__":
    S = "abcdddeeeeaabbbcd"
    S = "abbxxxxzzy"
    S = "aaabbbaaa"
    print Solution().largeGroupPositions(S)
