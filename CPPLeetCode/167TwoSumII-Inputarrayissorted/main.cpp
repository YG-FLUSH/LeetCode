#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> _map;
        vector<int>::const_iterator end = numbers.cend();
        int j=0;
        for(vector<int>::iterator i=numbers.begin(); i < end; ++i, ++j){
            int before_num = target - *i;
            auto map_iter = _map.find(before_num);
            if(map_iter != _map.end()){
                int a[2] = {map_iter->second+1, j+1};
                return vector<int>(a, a+2);
            }
            else{
                _map[*i] = j;
            }
        }
        return vector<int>(2, 0);
    }
};

int main(){
    int a[] = {1, 2, 3, 4};
    vector<int> numbers(a, a+sizeof(a)/sizeof(int));
    auto result = Solution().twoSum(numbers, 6);
    vector<int>::iterator result_end = result.end();
    for(vector<int>::iterator i=result.begin(); i < result_end; ++i){
        cout << *i << " ";
    }
    cout << endl;
}
