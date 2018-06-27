#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> result;
        vector<int>::iterator nums1_end = nums1.end();
        for(vector<int>::iterator i=nums1.begin(); i < nums1_end; ++i){
            auto num = find<vector<int>::iterator, int>(nums2.begin(), nums2.end(), *i);

            if(num != nums2.end()){
                result.insert(*num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};


int main(){
    const int num = 6;
    int a[num] = {1, 2, 3, 4, 5, 6};
    vector<int> nums1(a, a+num);
    vector<int> nums2(a+3, a+num);
    vector<int> result = Solution().intersection(nums1, nums2);
    vector<int>::iterator result_end = result.end();
    for(vector<int>::iterator i=result.begin(); i < result_end; ++i){
        cout << *i << " ";
    }
    cout << endl;
}
