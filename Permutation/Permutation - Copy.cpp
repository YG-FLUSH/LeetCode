#include <string>
#include <iostream>
#include <algorithm>//utility

//answer:http://blog.csdn.net/chen895281773/article/details/12357703
using namespace std;
class Solution {      
    public:
    string getPermutation(int n, int k) {  
        string sb ;  
        for(int i=1; i<=n; i++) {sb+=i+'0';}  
        string ret;  
          
        int* factor = new int[n];  
        factor[0] = 1;  
        for(int i=1; i<n; i++) { factor[i] = factor[i-1] * i;}  
         
        k--;    // note factorial number begins from 0 instead of 1  
        for(int i=n-1; i>=0; i--){              
            int code = k/factor[i];  
            k = k%factor[i];  

            ret+=sb[code];
            sb.erase(code,1);              
        }  
          
        return ret;  
    }  
}  ;

int main()
{
	Solution s;
//	int n =3;
//	for(int i=0;i<n;i++)
	// s.getPermutation(n,i);
	cout <<s.getPermutation(1,1);
	return 0;
}