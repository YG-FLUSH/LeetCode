Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

思路：
    1. 建立二维买入卖出收益数组
    2. 遍历数组寻找收益大于0的

    7 1  5  3 6 4
7   
1  -6 
5  -2 4
3  -4 2 -2 
6  -1 5  1 3
4  -3 3 -1 1 -2


[
[]
[0]
[0 0]
[0 0 0]
]
