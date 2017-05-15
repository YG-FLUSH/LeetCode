#include <iostream>
#include <unordered_set>
#include <string >
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		for(int num=1;num<=s.size();++num)
		{
			for(int pos =0; pos<=s.size()-num;++pos)
			{
				string str(s.begin()+pos,s.begin()+pos+num);
				if(dict.find(str)!=dict.end())
				return true;
			}
		}
		return false;
    }
};
int main()
{
	Solution s;
	
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	string str;
	while(str!="quit")
	{
		getline(cin,str);
		if(s.wordBreak(str,dict))
		cout << "true"<<endl;
		else
		cout << "false"<<endl;
	}
		return 0;	
	
}
