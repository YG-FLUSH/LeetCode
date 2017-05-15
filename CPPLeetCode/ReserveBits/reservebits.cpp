#include<iostream>
#include<string>
using namespace std;
#define uint32_t  unsigned int 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t a=0;
        for(int i=0; i<=31; i++)
		{
			if((1<<i)&n)
			{
				a|=1<<31-i;
			}
			else
			{
				a&=~(1<<31-i);
			}
		}
		return a;
    }
	
	void showBits(uint32_t n) 
	{
		for(int i=31; i>=0; i--)
		{
			if (n&(1<<i))
			{
				cout << "1";
			}
			else
			{
				cout  << "0";
			}
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	uint32_t b = 2147483648;
	s.showBits(b);
	uint32_t a=s.reverseBits(b);
	s.showBits(a);
	cout << a;
}