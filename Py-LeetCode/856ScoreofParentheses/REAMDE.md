Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6


思路:
    * 字符串从左到右匹配括号,即记录左括号与右括号的个数，数量相等时，为一个数字
    * 若字符串足够长，则从上一个完整匹配的数字位置开始，继续递归第一步，直到字符串结尾
    * 针对一个数字字符串，内部递归，重复第一步，并将数字结果相加,对于不可再递归的数字，即()相邻时，返回1
    * 故两层递归即可完成解析。
