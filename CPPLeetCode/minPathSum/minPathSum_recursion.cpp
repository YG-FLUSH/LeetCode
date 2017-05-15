#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int s = grid.size();
		if(s==0)
		return 0;
		return minNlftup(2*s-1,s-1,s-1,grid);
    }
typedef	enum pos{middle,left,up,end} Position;
	int minNlftup(int n,int x,int y,vector<vector<int> > &grid)
	{
		Position pos = checkBound(x,y);
		int sum = grid[y][x];
		if(pos == middle)
		{
			int left = minNlftup(n-1,x-1,y,grid);
			int up = minNlftup(n-1,x,y-1,grid);
			return sum+(left<up?left:up);
		}
		else if(pos == left)
		{
			int up = minNlftup(n-1,x,y-1,grid);
			return sum+up;
		}
		else if(pos == up)
		{
			int left = minNlftup(n-1,x-1,y,grid);
			return sum+left;
		}
		else 
		{
			return sum;
		}
	}
	Position checkBound(int x, int y)
	{
		if(x == 0 || y == 0)
		{
			if(x == 0 &&y != 0)
			{
				return left;
			}
			else if(x != 0 && y == 0)
			{
				return up;
			}
			else
			{
				return end;
			}
		}
		else
		{
			return middle;	//
		}
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