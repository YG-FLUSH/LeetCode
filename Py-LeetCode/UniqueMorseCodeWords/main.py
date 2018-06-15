#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/15

class Solution(object):
    mc_chars = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        mc_words = []
        for word in words:
            mc_word = []
            for c in word:
                i = ord(c) - ord('a')
                mc_word.append(self.mc_chars[i])
            mc_words.append("".join(mc_word))
        return len(set(mc_words))



