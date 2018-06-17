#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/15


class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        if not s:
            return False

        has_dot = False
        has_e = False
        has_digit = False

        i = 0
        first_c = s[i]
        if not first_c.isdigit():
            if first_c == ".":
                has_dot = True
                if i + 1 > len(s)-1:
                    return False
                if not s[i+1].isdigit():
                    return False
            elif first_c in ("+", "-"):
                if i + 1 > len(s)-1:
                    return False
                if not s[i+1].isdigit():
                    return False
            else:
                return False
        else:
            has_digit = True

        i += 1
        while i < len(s):
            c = s[i]
            if not c.isdigit():
                if c == ".":
                    if not has_dot:
                        has_dot = True
                        if i + 1 > len(s)-1:
                            return True
                        if not s[i+1].isdigit():
                            return False
                    else:
                        return False

                elif c == "e":
                    if not has_e:
                        has_e = True
                        if i + 1 > len(s)-1:
                            return False
                        if not s[i+1].isdigit():
                            return False
                    else:
                        return False
                else:
                    return False
            else:
                has_digit = True
            i += 1

        return has_digit


if __name__ == "__main__":
    s = "3."
    print Solution().isNumber(s)

