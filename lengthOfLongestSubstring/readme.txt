Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 For "bbbbb" the longest substring is "b", with the length of 1.
 
 //低效的做法
 //用unordered_map<char,int> 存字母及字母所在字符串的位置，再查找
 //必然遍历一次，每次遍历都在map里查找
 //找不到存入，找到维护一个max变量，保存此长度，再从找到的字符的下一个字符位置重新开始。
 
 
 //维护字符串起始位置bpos
 //前向指针遇到相同字符，其实位置则越过该字符，即bpos++
