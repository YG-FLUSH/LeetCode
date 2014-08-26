#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <list>
#include <iterator>
using namespace std;
struct T	//：struct 的成员默认是公有的，而类的成员默认是私有的。struct 和 class 在其他方面是功能相当的。
{

	public:
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
	string  reverse(string &s)
	{
		string result;
		list<string> ls;
		split(ls,s," ");
		string temp;
	//	list<string>::reverse_iterator ri = ls.rbegin()+1;	//为什么迭代器不能这样呢？

		list<string>::reverse_iterator ri = ls.rbegin();
		if(ls.size()==0)
		return "";
		result = *ri;
		for(ri++;ri!=ls.rend();ri++)
		{
			result += " "+*ri ;
		}
		
		return result;
	};

};
void main()
{
	struct T t;
	string st;
	while(st!="quit")
	{
		getline(cin,st);
	//string sub = st.substr(string::npos); //数组越界
	std::cout << "|"<<t.reverse(st) << "|";
	}
	cout <<"in file"<<__FILE__<<" (line:"<<__LINE__<<")";
}