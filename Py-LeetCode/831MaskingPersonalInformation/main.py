#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/23

class Solution(object):

    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        if "@" in S:
            return self.mask_email(S)
        else:
            return self.mask_phone(S)

    def mask_phone(self, S):
        digits = []
        for s in S:
            if s.isdigit():
                digits.append(s)
        if len(digits) == 10:
            return "***-***-" + "".join(digits[-4:])
        extra_star = len(digits) - 10
        return "+" + "*"*extra_star + "-***-***-" + "".join(digits[-4:])

    def mask_email(self, S):
        S = S.lower()
        firstname, others = S.split("@")
        firstname = firstname[0] + "*" * 5 + firstname[-1]
        return firstname + "@" + others


if __name__ == "__main__":
    S = "86-(10)12345678"
    S = "AB@qq.com"
    S = "+(501321)-50-23431"
    print Solution().maskPII(S)
