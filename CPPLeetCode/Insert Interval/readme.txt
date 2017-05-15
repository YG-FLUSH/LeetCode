Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

思路：
	遍历一遍输入的interval，删除区间重复的项	new.start <start  && end <new.end
	新区间重整
	0||0		删除该项，继续
	
	|00|		直接返回！
	
	0|0|		重整区间	保留start,删除项	Scross = 1;
	|0|0		重整区间	保留end ，删除项	Ecross = 1;
															重建start,end
							
	00||		继续		保留start	开始没交叉，
	||00		继续		保留end  	结果没交叉，
	
	接壤的情况
	
	效率太低！
	
	输入的interval是递增的！
	输出的interval也是递增的
	
	可以从左到右遍历寻找插入点 用sIn保存
	
	从右至左遍历寻找插入点	用eIn 保存
	
	删除两个插入点的中间项
	
	需要注意的是边界问题！！
	从什么地方删除
	保存的是什么值，该不该删除！！
	
	
	