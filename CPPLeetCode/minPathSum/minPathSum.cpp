#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int s = grid.size();
		if(s==0)
		return 0;
		vector<vector<int> > minPath (grid);
		int &col =s;
		int &row =s;
		for(int i=1;i<row;i++)
		{
			minPath[0][i] = grid[0][i]+minPath[0][i-1];
		}
		for(int i=1;i<col;i++)
		{
			minPath[i][0] = grid[i][0]+minPath[i-1][0];
		}
		for(int i = 1;i<col;i++)
		{
			for(int j = 1;j<row;j++)
			{
				minPath[i][j] = min<int>(minPath[i-1][j],minPath[i][j-1])+grid[i][j];
			}
		}
		return minPath[col-1][row-1];	
    }
};
int main()
{
	vector<vector<int> > va;
	const int n=30;
	va.resize(n);
	for(int i=0;i<va.size();i++)
	{
		va[i].resize(n);
	}
	int c=0;
	
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<n;j++)
		{	
			c++;
			va[i][j] = c;
		}
	}
	Solution s;
	cout << s.minPathSum(va);
	
	return 0;
}