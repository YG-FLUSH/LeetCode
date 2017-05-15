#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows <= 1){
                return s;
            }
            vector<string> _ls(numRows, "");
            int _len_line_zigzag  = 2 * numRows - 2;
            string::iterator itend = s.end();
            int i=0;
            for(string::iterator it = s.begin(); it!= itend; ++it, ++i){
                int r = i % _len_line_zigzag;
                if (r > numRows -1){
                    r = _len_line_zigzag - r;
                }
                _ls[r] += *it;
            }
            string result = "";
            vector<string>::iterator lsend = _ls.end();
            for(vector<string>::iterator lsit = _ls.begin(); lsit != lsend; ++lsit){
                result += *lsit;
            }
            return result;
        }
};

int main(int args, char * kargs[]){
    string s = "abcdefghi";
    int n = 5;
    cout << Solution().convert(s, n) << endl;
}
