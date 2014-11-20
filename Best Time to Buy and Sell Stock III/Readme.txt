Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


You may complete at most two transactions!  at most 至多！！！不超过！！所以可以一次也可以两次！，不能连续两次买入

曲解：
//在一个数组里找不可逆遍历的寻找最大差值
//如 a[5]={2,1,3,4,2} 则最大差值在1,4之间，为3

//思路： 维护一个起始指针指向顺序遍历最小的数，维护一个当前指针遍历整个数组。O(n)，维护max变量;
//当前指针每移动一次，计算一次与起始指针的差值。>0则与max比较，再改变max值，<0则改变起始指针为当前指针，保证了起始指针永远是遍历的最小的指针。


//在一个数组里找不可逆遍历的寻找最大差值
//如 a[5]={2,1,3,4,2} 则最大差值在1,4之间，为3
//如 a[5]={2,1,2,0,1} 则最大差值在1,2之间，0,1之间，和为2

思路：找到一个最大，然后以最大为边界找出能够分裂成两次，使得和大于该最大值，否则以最大的外边界寻找次大。	//不知道为什么总会出错

思路：从左到右维护一个最小值min，并将每次的最大差值保存下来；从右至左维护一个最大值max，同样保存下最大差值。
这样得到两个数组，一个递增，一个递减，只要知道两者在同一个点处达到最大即可。递增，意味着从开始到某个下标可能的最大值，递减，意味着从结束到某个下标的最大值。




