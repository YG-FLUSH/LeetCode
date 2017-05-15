#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k){
            return "0";
        }
        int removed_count = 0;
        string num_copy = "";
        while (removed_count < k){
            int size = num.size();

            for(int i=0; i < size; ++i){
                if (removed_count < k && i+1 < size && num[i] > num[i+1]){
                    ++removed_count;
                }
                else{
                    if(num_copy.empty() && num[i] == '0'){
                        continue;
                    }
                    num_copy.push_back(num[i]);
                }
            }
            if (num_copy.size() == size){
                break;
            }
            num = num_copy;
            num_copy = "";
        }
        if(removed_count == k){
            num_copy = num;
        }

        int diff_size = k - removed_count;
        if(diff_size > 0){
            num_copy.erase(num_copy.end() - diff_size , num_copy.end());
        }
        if (num_copy.empty()){
            cout << "hhh" << endl;
            return "0";
        }
        return num_copy;
    }
};

int main(int args, char* kargs[]){
    string s = "11111";
    /* cout << Solution().removeKdigits(s, 2) << " " << s << endl; */
    /* s = "12"; */
    /* cout << Solution().removeKdigits(s, 1) << " " << s << endl; */
    s = "1432219";
    cout << Solution().removeKdigits(s, 3) << " " << s << endl;

}
