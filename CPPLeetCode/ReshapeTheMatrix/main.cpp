#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int > > matrixReshape(vector<vector<int > >& nums, int r, int c) {
        int rows = nums.size();
        if (!rows){
            return nums;
        }
        int cols = nums[0].size();
        if (rows * cols != r * c){
            return nums;
        }
        vector<vector<int > > result(r, vector<int>(c));
        for(int i=0; i < r; ++i){
            for(int j=0; j < c; ++j){
                int row = (i*c + j) / cols;
                int col = (i*c + j) % cols;
                result[i][j] = nums[row][col];
            }
        }
        return result;
    }
};

int main(){
    vector<int > row_1 = {1, 2};
    vector<int > row_2 = {3, 4};
    vector<vector<int > > nums = {row_1, row_2};
    vector<vector<int > > result = Solution().matrixReshape(nums, 1, 4);
    for(vector<vector<int > >::iterator iter = result.begin(); iter != result.end(); iter++){
        for (vector<int >::iterator ii = (*iter).begin(); ii != (*iter).end(); ii++){
            cout << *ii << ",";
        }
        cout << endl;
    }
    return 0;
}
