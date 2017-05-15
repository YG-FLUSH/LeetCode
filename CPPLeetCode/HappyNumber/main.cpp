#include<iostream>
#include<set>
#include<sstream>
#include<assert.h>
using namespace std;
string InttoString(int n){
    stringstream result;
    result << n;
    return result.str();
}


class Solution{
    public:
        bool isHappy(int n){
            int m = 1;
            set<int> temp_set;
            temp_set.insert(n);
            while(true){
                m = sumSquare(n);
                if(m == 1){
                    return true;
                }
                else if(temp_set.find(m) != temp_set.end()){
                    return false;
                }
                else{
                    temp_set.insert(m);
                    n = m;
                }
            }
        }
        int sumSquare(int n){
            string str = InttoString(n);
            int result = 0;
            for(int i=0; i < str.length(); i++){
                result += int(str[i] - '0') * int(str[i] - '0');
            }
            return result;
        }
};

int main(){
    assert(Solution().isHappy(19) == true);
    assert(Solution().isHappy(20) == false);

}
