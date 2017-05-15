#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        for(int i=1; i<nums.size(); ++i){
            nums[i] = nums[i] + nums[i-1];
        }
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        if(i==0){
            return this->nums[j];
        }
        else{
            return this->nums[j] - this->nums[i-1];
        }
    }
private:
    vector<int> nums;

};

int main(){
    int a[] = {1, 2, 3, 4};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    NumArray numArray(nums);
    assert(numArray.sumRange(0, 1)==3);
    assert(numArray.sumRange(0, 3)==10);
}

