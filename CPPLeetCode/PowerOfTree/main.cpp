#include<iostream>
#include<float.h>
#include<cmath>
using namespace std;
class Solution {
	public:
	bool isPowerOfThree(int n) {
		if (n == 0) return false;
		double res = log(n)/log(3);
		return abs(res - rint(res)) < FLT_MIN;
	}
};

int main(){
	cout << Solution().isPowerOfThree(100);
}
