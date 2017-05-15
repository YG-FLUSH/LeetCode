#include<iostream>
#include<cmath>
#include<float.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        double res = log(n)/log(2);
        cout << res << endl;
        return abs(res-rint(res)) < FLT_MIN;
    }
};

int main(){
    cout << Solution().isPowerOfTwo(2);

}
