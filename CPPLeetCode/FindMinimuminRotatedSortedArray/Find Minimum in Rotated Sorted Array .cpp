#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
		int stop =0;
        binarysearch(num,0,num.size()-1,&stop);
		if(stop==1)
		return min;
		else
		return num[0];
    }
	void binarysearch(vector<int> &num,int left,int right,int *stop)
	{
		if(left>=right||*stop) return;
		int mid = (left+right)/2;
		if(num[mid]>num[mid+1])
		{	
			min = num[mid+1];
			*stop =1;
		}
		else
		{
			binarysearch(num,left,mid,stop);
			binarysearch(num,mid+1,right,stop);
		}
	}
	private:
	int min;
};

int main()
{

	int const n=1;
	Solution s;
	//int a[n]={1,2,4,5,6,7};
	int a[n] ={1};
	vector<int> v(a,a+n);
	cout << s.findMin(v)<<endl;
}