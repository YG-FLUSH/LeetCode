#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        initStore(numRows);
		calpas(numRows);
		for(int i=0;i<numRows;i++)
		{
			Re.push_back(arrayElement[i]);
		}
		return Re;
    }
	~Solution()
	{
			delete [] arrayElement ;	
	}
private:
	void initStore(int numRows)
	{
		arrayElement = new vector<int> [numRows];	//vector<int>指针对象用resize进行在堆上的重新分配空间 
		for(int n=0;n<numRows;n++)
		{
			arrayElement[n].resize(n+1);
		}
	}
	void calpas(int numRows)		//用递归调用会重复很多次！
	{
		for(int n=0;n<numRows;n++)
			for(int k=0;k<=n;k++)
			{
				if(k==0||k==n){arrayElement[n][k]=1;}
				else
				{
					arrayElement[n][k]=arrayElement[n-1][k-1]+arrayElement[n-1][k];
				}
			}
	}
	vector<vector<int> > Re;
	vector<int> *arrayElement;
};

int main()
{
	Solution s;
	vector<vector<int> > R=s.generate(30);
	for(vector<vector<int> >::iterator i=R.begin();i!=R.end();i++)
	{
			for(vector<int>::iterator j= (*i).begin();j!=(*i).end();j++)
			{
				cout << *j<<" ";
			}
		cout << endl;
	}
	


	return 0;
}