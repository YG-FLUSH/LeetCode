
[hard]
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5



1, 2, 3, 5, 6, 7, 8, 10, 11

8, 11, 12

1, 2, 3, 5, 6, 7, 8,
8-, 10, 11, 11-, 12



1. O(n+m)的解法:
    * 将两个数组合并，取第 n+m/2的元素

2. O(log(m+n)) 的解法:
    * 不交叉的两个数组，取第n+m/2个元素
    * 交叉的数组:
        * 设第一个数组第一个元素小于第二个数组的第一个元素
        * 第一个数组二分逼近第二个数组的第一个元素, 取最后一个小于第二个数组第一个元素的index,  知道index即知道了交叉重复的元素个数
        * 第一个数组交叉部分的元素个数为 n - index
        * 逼近第二个元素，获取交叉部分的为index2


