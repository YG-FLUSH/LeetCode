#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/03

class Solution(object):

    def getkth(self, nums1, nums2, total_len):
        # 保证len(nums1) <= len(nums2)
        if len(nums1) > len(nums2):
            return self.getkth(nums2, nums1, total_len)

        if len(nums1) == 0:
            return nums2[total_len-1]

        if total_len == 1:
            return min(nums1[0], nums2[0])


        nums1_min = min(len(nums1), total_len/2)
        nums2_min = min(len(nums2), total_len/2)
        if nums1[nums1_min - 1] > nums2[nums2_min - 1]:
            return self.getkth(nums1, nums2[nums2_min:], total_len-nums2_min)
        else:
            return self.getkth(nums1[nums1_min:], nums2, total_len-nums1_min)


    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        total_len = (len(nums1) + len(nums2) + 2) / 2
        total_len1 = (len(nums1) + len(nums2) + 1) / 2
        return (self.getkth(nums1, nums2, total_len) + self.getkth(nums1, nums2, total_len1)) / 2.0


if __name__ == "__main__":

    print Solution().findMedianSortedArrays([1, 2], [3, 4])
