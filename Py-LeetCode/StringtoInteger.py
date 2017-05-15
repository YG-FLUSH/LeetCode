"""
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

"""

class Solution(object):

    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        try:
            return int(str)
        except:
            str = str.strip()
            if not str[0].isdigit() and not str[0] in ("-", "+"):
                return 0
            for i, s in enumerate(str):
                if not s.isdigit() and i != 0:
                    try:
                        return int(str[:i])
                    except:
                        return 0
            return 0


if __name__ == "__main__":
    s = "+-2"
    print Solution().myAtoi(s)
