#include <string.h>
#include <string>
#include <list>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string S(s);
		list<string> ls;
		split(ls,S," ");
		if(ls.size()==0)
		return 0;
		else
		{
			return strlen(ls.back().c_str());
		}
    }
	list<string> & split(list<string> &ls,const string &src,const string &seporator)
	{
		string temp ;
		string::size_type start=0,index;
		string str = src;
		do
		{
			index = str.find_first_of(seporator,start);
			if(index!=string::npos)
			{
				temp = str.substr(start,index-start);
				start = str.find_first_not_of(seporator,index);
				if(temp != "")ls.push_back(temp);
				if(start==string::npos)  return ls;
			}
		}while(index!=string::npos);
		
		temp = str.substr(start);
		ls.push_back(temp);
		return ls;
	}
	
};

int main()
{
	Solution s;
	string sin;
	while(sin!="quit")
	{
		getline(cin,sin);
		if(sin!="quit")
		cout << s.lengthOfLastWord(sin.c_str())<<endl;
	}
	
}