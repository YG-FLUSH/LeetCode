#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

		typedef struct M{
		int max;
		int left;
		int right;
	} Max;
    int maxProfit(vector<int> &prices) 
	{
		Max max ;
		memset(&max,0,sizeof(max));
		if(!maxfind(prices,max))return max.max;	//递减输入0
		Max m1,m2 ;
		memset(&m1,0,sizeof(m1));
		memset(&m2,0,sizeof(m2));
		dispatch(prices,max,m1,m2);
		return nextfind(prices,max);
    }
	int nextfind(vector<int> &prices,Max &m)
	{
		int b=0;
		int max =0;
		for(int i=0;i<m.left;i++)
		{
			int diff =prices[i]-prices[b];
			if(diff>0)
			{
				if(diff>max)
				{
					max = diff;
				}
			}
			else if(diff<0)
			{
				b=i;
			}
		}
		b= m.right;
		for(int i= m.right+1;i<prices.size();i++)
		{
			int diff =prices[i]-prices[b];
			if(diff>0)
			{
				if(diff>max)
				{
					max = diff;
				}
			}
			else if(diff<0)
			{
				b=i;
			}
		}
		return m.max+max;
	}
	
	bool maxfind(vector<int> &prices,Max &m)
	{
		int b=0;
		bool found = false;
		for(int i=0;i<prices.size();i++)
		{
			int diff =prices[i]-prices[b];
			if(diff>0)
			{
				if(diff>m.max)
				{
					m.max = diff;
					m.left = b;
					m.right = i;
					found =true;
				}
			}
			else if(diff<0)
			{
				b=i;
			}
		}
		return found;
	}
	bool dispatch(vector<int> &prices,Max &m,Max &m1,Max &m2)
	{
		bool flag = false;
		for(int i = m.right-1;i>m.left+1;i--)
		{
			for(int j =m.left+1;j <i;j++)
			{
				if(m.max<(prices[j]-prices[m.left])+(prices[m.right]-prices[i]))
				{ 
					cout << "dispatch " << i <<" " <<j<<endl;
					m1.left = m.left;
					m1.right = j;
					m1.max = (prices[j]-prices[m.left]);
					
					m2.left = i;
					m2.right = m.right;
					m2.max = (prices[m.right]-prices[i]);
					m.max = m1.max+m2.max;
					flag = true;
					continue;
				}
			}
		}
		return flag;
	}
};

int main()
{
	const int num =13;
	Solution s;
	int a[num]={2,6,8,7,8,7,9,4,1,2,4,5,8};	//为何是4的时候会出现内存错误？？？
	vector<int > prices(a,a+num);
	cout << s.maxProfit(prices);
	return 0;
}