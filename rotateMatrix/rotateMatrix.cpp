#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) 
	{
		int n = matrix.size()-1;
		int nm;
		if(n%2==1){nm=n+1/2;}
		else{nm = n/2;}
		for(int i =0;i<nm;i++)
		{
			for(int j=i;j<n-i;j++)
			{
				swapcorner(j,i,matrix,n);
			}
		}
		
    }
	private:
	void swapcorner(int xindex,int yindex,vector<vector<int> > &matrix,int n )
	{
		if(n>0)
		{
			int cx,cy;
			int temp = matrix[yindex][xindex];
			for(int i =0 ;i<3;i++,yindex = cy,  xindex= cx)
			{
				reconvert(xindex,yindex,cx,cy,n);
				matrix[yindex][xindex] = matrix[cy][cx];		
			}
			matrix[cy][cx] = temp;
		}
	}
	void reconvert(int &x1,int &y1,int &x2,int &y2,int n)
	{
		x2 = y1;
		y2 = n - x1;
	}
};


void showMatrix(const vector<vector<int> > &matrix )
{
	static const int max=4;
	for(int n=0;n<max;n++)
	{
		for(int m=0;m<max;m++)
		{
				
			cout<<matrix[n][m]<<" ";
		}
		cout <<endl;
	}
}
int main()
{
	static const int max=4;
	Solution s;
	vector<vector<int> > matrix;
		matrix.resize(max);
		for(int n=0;n<max;n++)
		{
			matrix[n].resize(max);
		}
		int i=0;
		for(int n=0;n<max;n++)
		{	

			for(int m=0;m<max;m++)
			{
				matrix[n][m]=i;
				i++;
			}
		}
	showMatrix(matrix);
	cout <<endl;
	s.rotate(matrix);
	showMatrix(matrix);
	return 0;
}

