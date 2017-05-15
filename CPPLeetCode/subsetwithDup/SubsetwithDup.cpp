#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		
		 for(int m =0; m<=S.size();m++)
		 {
			if(m==0)
			{
				Result.push_back(vector<int>());
				continue;
			}
		 	int *inx = new int[m];
			combine(S,S.size(),m,inx,m);
			delete[] inx;
		 }
		 return Result;
    };
	void combine(vector<int> &s, int n, int m,  int b[], const int M )
	{ 
		 for(int i=n; i>=m; i--)   // 注意这里的循环范围
		 {
			  b[m-1] = i - 1;
			  if (m > 1)
				combine(s,i-1,m-1,b,M);
			  else                     // m == 1, 输出一个组合
			  {   
				  vector<int> re;
				
				for(int j = 0;j<M;j++)
				{
					re.push_back(s[b[j]]);
				}
				sort<vector<int>::iterator >(re.begin(),re.end());
				bool duplicateflag=false;
				for(vector<vector<int> >::iterator it = Result.begin();
													it != Result.end();	
																	it++)
				{
					if(*it == re)
					{
						duplicateflag=true;
						break;
					}					
				}
				if(!duplicateflag)
				Result.push_back(re);
			  }
		 }
	}
	private:
	vector<vector<int> >Result;
};
	void combine(vector<int>&s,int inx[],int totalnum,int picknum,const int PickNum)
	{
		for(int i = totalnum; i>=picknum;i--)
		{
			inx[picknum-1] = i-1;	
			if(picknum>1)
			{
				combine(s,inx,totalnum-1,picknum-1,PickNum);
			}
			else
			{
			/*
				vector<int> re;
				
				for(int j = 0;j<PickNum;j++)
				{
					cout << s[inx[j]];
					re.push_back(s[inx[j]]);
				}
				cout << endl;
				bool duplicateflag=false;
				for(vector<vector<int> >::iterator it = Result.begin();
													it != Result.end();	
																	it++)
				{
					if(*it == re)
					{
						duplicateflag=true;
						break;
					}					
				}
				if(!duplicateflag)
				Result.push_back(re);
				*/
			}
		}
	}

int main()
{
	Solution solu;
	const int num =3;
	int su[num]={4,1,0};
	int b[num];

	vector<int > s(su,su+num);
		//combine(s,num,2,b,2);
	vector<vector<int> > R= solu.subsetsWithDup(s);

	for(vector<vector<int> >::iterator i=R.begin();i!=R.end();i++)
	{
		for(vector<int>::iterator j= (*i).begin();j!=(*i).end();j++)
		{
			cout << *j;
		}
		cout << endl;
	}

	return 0;
}