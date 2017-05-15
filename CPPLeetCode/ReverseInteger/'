#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool is_negative = false;
        unsigned int _x;
        if (x < 0){
            is_negative = true;
            _x = -x;
        }
        else{
            _x = x;
        }
        unsigned int MAX_INT = (1 << 31) ;
        int i = 10;
        vector<int> result;
        while(_x / i != 0){
            int r = _x % i / (i/10);
            result.push_back(r);
            i *= 10;
        }
        result.push_back(_x % i / (i/10));

        vector<int>::reverse_iterator itend = result.rend();
        int j = 0;
        int res = 0;
        for (vector<int>::reverse_iterator rit=result.rbegin(); rit != itend; ++rit, ++j){

            if (*rit == 0 && res == 0)
                continue;

            float _pow = (*rit) * pow(10, j);
            res += _pow;
        }
        if(is_negative){
            res = -res;
        }
        return res;
    }
};


int main(int args, char * kargs[]){
     cout << Solution().reverse(1000000009) << endl;
}
