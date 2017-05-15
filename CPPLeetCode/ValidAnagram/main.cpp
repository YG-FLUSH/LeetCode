#include<iostream>
#include<unordered_map>

using namespace std;

template<class K, class V>
ostream& operator << (ostream& out, unordered_map<K, V>& map){
    for(typename unordered_map<K, V>::iterator iter = map.begin();
        iter != map.end(); ++iter){
        out << iter->first << ":" << iter->second <<endl;
    }
    return out;
}

class Solution {
public:
    bool isAnagram(string &s, string &t) {
        unordered_map<char, int> s_frequency = this->get_char_frequency(s);
        unordered_map<char, int> t_frequency = this->get_char_frequency(t);
        return s_frequency == t_frequency;
    }
    unordered_map<char, int> get_char_frequency(string& str){
        unordered_map<char, int> frequency_map;
        for(int i=0; i < str.length(); ++i){
            if(frequency_map.find(str[i]) == frequency_map.end()){
                frequency_map[str[i]] = 1;
            }
            else{
                ++frequency_map[str[i]];
            }
        }
        return frequency_map;
    }
};


int main(){
    string s = "abc123ac";
    string t = "cababcab";
    cout << Solution().isAnagram(s, t);
}
