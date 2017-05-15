#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n)
	{
		init(n);
		NQueen(n-1);
		return total;
	};
	void init(int n)
	{
		total=0;
		va.resize(n);
		for(int i=0;i<va.size();i++)
		{
			va[i].resize(n);
		}
		update_dat(n);
	};
	void NQueen(int n)
	{
		int x=0;
		for(;x<va.size();x++)
		{
			if(va[n][x]==0)
			{
				
				if(n==0)
				{
					++total;
					return ;
				}
				else
				{
					modify(va,x,n);
					NQueen(n-1);
					rollback(va,x,n);
				}
			}
		}				
		return ;
	};
	void show()
	{
		for(int y=0;y<va.size();y++)
		{
			for(int x = 0;x<va.size();x++)
			{
				cout << va[y][x] << " ";
			}
			cout << endl;
		}
				cout << endl;
	};

	void init(int n)
	{
		total=0;
		va.resize(n);
		for(int i=0;i<va.size();i++)
		{
			va[i].resize(n);
		}
		update_dat(n);
	};

	
	void update_dat(int n)
	{
		for(int i=0; i<n;i++)
		{
			for(int j=0; j<n;j++)
			{
				va[i][j] = 0;
			}
		}
	};
		void modify(vector<vector<int> > & va,int x,int y)
	{
		int s =va.size();
		for(int i =0; i<s;i++)
		{
			++va[i][x]  ;
			++va[y][i] ;
			if(0<=x+i&&x+i<s&&0<=y+i&&y+i<s)
			++va[y+i][x+i];
			if(0<=x-i&&x-i<s&&0<=y-i&&y-i<s)
			++va[y-i][x-i];
			if(0<=x+i&&x+i<s&&0<=y-i&&y-i<s)
			++va[y-i][x+i];
			if(0<=x-i&&x-i<s&&0<=y+i&&y+i<s)
			++va[y+i][x-i];
		}
	};
	void rollback(vector<vector<int> > & va,int x,int y)
	{
		int s =va.size();
		for(int i =0; i<s;i++)
		{
			--va[i][x]  ;
			--va[y][i] ;
			if(0<=x+i&&x+i<s&&0<=y+i&&y+i<s)
			--va[y+i][x+i];
			if(0<=x-i&&x-i<s&&0<=y-i&&y-i<s)
			--va[y-i][x-i];
			if(0<=x+i&&x+i<s&&0<=y-i&&y-i<s)
			--va[y-i][x+i];
			if(0<=x-i&&x-i<s&&0<=y+i&&y+i<s)
			--va[y+i][x-i];
		}
	};
		void initb(int n)
	{
		vb.resize(n);
		for(int i=0;i<vb.size();i++)
		{
			vb[i].resize(n);
		}
		update_datb(n);
	};
	void update_datb(int n)
	{
		for(int i=0; i<n;i++)
		{
			for(int j=0; j<n;j++)
			{
				va[i][j] = 0;
			}
		}
	};
		void showb()
	{
		for(int y=0;y<vb.size();y++)
		{
			for(int x = 0;x<vb.size();x++)
			{
				cout << vb[y][x]<<" ";
			}
			cout << endl;
		}
				cout << endl;
	};	
	};	
	private:
		vector<vector<int> > va;
		vector<vector<bool> > vb;	
		int total;
		bool flag;
};
int main()
{
	Solution s;
	cout<<s.totalNQueens(4);
	return 0;
}