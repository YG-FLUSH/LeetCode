#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		int n = s.size();
		int j=0;
		string filt(s);
		for(int i=0;i<n;i++)
		{
			if((s[i]>='A'&&s[i]<='Z')||(s[i]<='z'&&s[i]>='a')||(s[i]>='0'&&s[i]<='9'))
			{
				filt[j]= s[i];
				j++;
			}
		}
		string sub = filt.substr(0,j);	
		int subs = sub.size();
        for(int i=0;i<subs/2;i++)
		{
			if((sub[i]>='A'&&sub[i]<='Z'))
			{
				if(sub[i]!=sub[subs-i-1])
				{
					if(sub[i]!=(sub[subs-i-1]-('a'-'A')))
					return false;
				}
			}
			if(sub[i]<='z'&&sub[i]>='a')
			{
				if(sub[i]!=sub[subs-i-1])
				{
					if(sub[i]!=(sub[subs-i-1]+('a'-'A')))
					return false;	
				}
			}
			if(sub[i]>='0'&&sub[i]<='9')
			{
				if(sub[i]!=sub[subs-i-1])
				{return false;}
			}
		}
		return true;
    }
};
int main(int arc,char *arv[])
{
	Solution s;
	if(s.isPalindrome("1a2"))
	cout << "true";
	else cout << "false";
	cout <<endl;
	return 0;
}