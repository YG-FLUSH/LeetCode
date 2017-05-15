#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerocount = 0;
        for(vector<int>::iterator i=nums.begin(); i < nums.end(); ){
            if(*i == 0){
                ++zerocount;
                i = nums.erase(i);
            }
            else{
                ++i;
            }
        }
        for(int i=0; i < zerocount; ++i){
            nums.push_back(0);
        }

    }
};

int main(){
    int a[] = {0};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    Solution().moveZeroes(nums);
    for(int i=0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
}
