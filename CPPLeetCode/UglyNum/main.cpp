#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        if(num % 2 == 0)
            return this->isUgly(num/2);
        if(num % 3 == 0)
            return this->isUgly(num/3);
        if(num % 5 == 0)
            return this->isUgly(num/5);
        return false;
    }
};

int main(){
    cout << Solution().isUgly(14);
    cout << Solution().isUgly(24);
}
