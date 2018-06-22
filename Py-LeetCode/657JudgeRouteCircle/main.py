#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/22

class Solution(object):

    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        #return (moves.count("L") == moves.count("R")) and (moves.count("U") == moves.count("D"))

        v_count, h_count = 0, 0
        for move in moves:
            if move == "U":
                v_count += 1

            elif move == "D":
                v_count -= 1

            elif move == "R":
                h_count += 1
            elif move == "L":
                h_count -= 1

        return v_count == 0 and h_count == 0

if __name__ == "__main__":
    moves = "LL"
    print Solution().judgeCircle(moves)
