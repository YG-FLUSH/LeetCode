#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>
using namespace std;
class Solution {  
public:  
  vector<int> twoSum(vector<int> &numbers, int target) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
          
        int len = numbers.size();  
        assert(len >= 2);             
          
        vector<int> ret(2, 0);  
          
        map<int, int> mapping;              // default all are 0  
        vector<long long> mul(len, 0);  
          
        for(int i = 0; i < len; i++)
		{
            mul[i] = (target - numbers[i])*numbers[i] ;  
              
            if(mapping[mul[i]] > 0)
			{        // not default 0  
                if(numbers[i] + numbers[mapping[mul[i]] - 1] == target)
				{  
                    ret[0] = mapping[mul[i]];  
                    ret[1] = i + 1;  
                    break;  
                }  
                  
            }
			else 
			{  
                mapping[mul[i]] = i + 1;    // larger than 0  
            }  
        }  
          
        return ret;  
    }  
};  
int main()
{
	Solution s;
	const int num =5;
	int ar[num] ={1,3,8,2,4};
	vector<int > vi(ar,ar+num);
	vector<int > numbers = s.twoSum(vi,6 );
	for(vector<int>::iterator it = numbers.begin();it!=numbers.end();it++)
	{
		cout << *it <<" ";
	}
	cout <<endl;
	return 0;
}