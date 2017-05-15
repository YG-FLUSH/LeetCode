class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        r = 0
        t = x
        while t:
            r *= 10
            r += t%10
            t = t/10

        return r == x
