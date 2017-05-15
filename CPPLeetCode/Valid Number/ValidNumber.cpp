#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
		int start =0;
		for(int i =0; s[i]==' '||s[i]=='\0';i++)
		{
			start ++;
			if(s[i]=='\0')
			return false;
		}
		bool flag1 = true, flag2 = true,flag3= false;
		for(int i=start;s[i]!='\0';i++)
		{
			if(s[i]>'9'||s[i]<'0')
			{
				if((flag1||flag3)&&s[i]=='.')
				{
					if(i==start&&(s[i+1]<'0'||s[i+1]>'9') )return false;	//点在最开始的位置
					flag1= false;
					continue;
				}
				if(flag2&&(s[i]=='e'||s[i]=='E'))
				{
					if(i==start||(s[i-1]<'0'||s[i-1]>'9')||(s[i+1]<'0'||s[i+1]>'9') )return false;	//点在最开始的位置
					flag2 =false;
					flag3 = true;
					if(s[i+1]=='+'||s[i+1]=='-')
					{
						i++;
					}
					continue;
				}
				
			if(s[i]== ' '&&(s[i+1] == ' '||s[i+1]=='\0'))continue;
				return false;
			}
			
		}
		return true;
    }
};
int main ()
{
	Solution s;
	string str("0e");
	if(s.isNumber(str.c_str())) cout << "true";
	else cout << "false";
	cout <<endl;
}

