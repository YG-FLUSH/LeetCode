#include<iostream>
#include<vector>
#include<unordered_map>

#include"../utils/util.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string& pattern, string& str) {
        vector<string> str_list;
        split(str, ' ', str_list);

        if(str_list.size() != pattern.length())
            return false;

        unordered_map<char, string> temp_map;
        unordered_map<string, char> reverse_map;
        for(int i=0; i < pattern.length(); ++i){
            if(temp_map.find(pattern[i]) == temp_map.end()){
                temp_map[pattern[i]] = str_list[i];
            }
            else if(temp_map[pattern[i]] == str_list[i]){
                continue;
            }
            else{
                return false;
            }

            if(reverse_map.find(str_list[i]) == reverse_map.end()){
                reverse_map[str_list[i]] = pattern[i];
            }
            else if(reverse_map[str_list[i]] == pattern[i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    string pattern = "abba";
    string str = "dog dog dog dog";
    cout << Solution().wordPattern(pattern, str);
}
