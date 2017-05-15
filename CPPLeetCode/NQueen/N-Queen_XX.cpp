#include <iostream>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
		int *a = new int [n];
		time =0;
		for(int i=0;i<n;i++)
		{
			a[i]=i+1;
		}
        permulation(a,n);
		delete [] a;
		return time;
    };
private:
	void permulation (int a [],int n)
	{
			if(n==0)
		{
			time ++;
		}
		for(int i =0;i<n;i++)
		{
			swap(a[0],a[i]);
			permulation(a+1,n-1);
			swap(a[0],a[i]);

		}
	};
	int time;
};
int main()
{
	Solution s;
	cout<<s.totalNQueens(4);
	return 0;
}