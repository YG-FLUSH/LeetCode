#include <string>
#include <iostream>
#include <algorithm>//utility
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
		string s= generateNs(n);
		 Permutation(s,k);
		 return result;
    }
	string generateNs(int n)
	{
		string s;
		for(int i=0;i<n;i++)
		{
			s +=(i+0x31);
		}
		return s;
	}
	inline void Permutation(string &s , int k)
	{
		flag = false;
		Permutation_(s,s.size(),0,k);
	}
	void Permutation_(string &s ,int N, int n, int & k)
	{
	
		if(flag == true) return ;
		if(n==N-1)
		{
			if(k==0)
			{
				flag = true;
				result = s;
			}
			else{k--;}
		}
		for(int i=n;i<N;i++)
		{
			swap(s[n],s[i]);
			Permutation_(s,N,n+1,k);
			swap(s[n],s[i]);
		}
	}

	private:
	bool flag;
	string result;
};

int main()
{
	Solution s;
//	int n =3;
//	for(int i=0;i<n;i++)
	//cout << s.getPermutation(n,i);
		cout << s.getPermutation(9,200000);
	return 0;
}