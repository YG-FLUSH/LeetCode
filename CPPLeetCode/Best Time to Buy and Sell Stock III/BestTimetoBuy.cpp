#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Solution{
public:
	int maxProfit(vector<int > &prices)
	{
		const int n = prices.size();
		if(n==0) return 0;
		int *l = new int [n];
		int *r = new int [n];
		memset(l,0,sizeof(int)*n);
		memset(r,0,sizeof(int)*n);
		int min =prices[0];
		for(int i =1;i<prices.size();i++)
		{
			l[i] = (prices[i] - min )>l[i-1]? (prices[i]-min) :l[i-1];
			min = prices[i]<min?prices[i]:min;
		}
		int max =prices[n-1];
		for(int i=prices.size()-2; i>=0; i--)
		{
			r[i] = max - prices[i] > r[i+1] ? max - prices[i]: r[i+1];
			max = max>prices[i]? max : prices[i];
		}
		int profit=0;
		for(int i =0 ; i< prices.size();i++)
		{
			profit = l[i]+r[i]>profit? l[i]+r[i]:profit;
		}
		delete l,r;
		return profit;
		
	}
};

int main()
{
		const int num =13;
	Solution s;
	int a[num]={2,6,8,7,8,7,9,4,1,2,4,5,8};	
	vector<int > prices(a,a+num);
	cout << s.maxProfit(prices);
	return 0;
}