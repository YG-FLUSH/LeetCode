Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.


思路：
1、字符串的搜索必须是相邻的；board[i][j]	，对应board[i-1][0--n]、board[i+1][0--n]、board[i][j-1]、board[i][j+1];

2、访问过的cell不能重新访问

3、word 每个字符进行单独的匹配。