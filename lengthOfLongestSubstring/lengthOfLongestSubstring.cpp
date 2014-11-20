#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int  map[256];
		memset(map,-1,sizeof(map));
		int bpos =-1;
		int max =0;
		for(int i = 0;i < s.size();	i++)
		{
			
			if(map[s[i]]>bpos)
			{
				
				bpos=map[s[i]];
			}
			int cmax=i-bpos;
			if( cmax> max)
			{
				max = cmax;
			}
			map[s[i]]=i;
		}
		return max;
    }
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("abceb");
	return 0;
}