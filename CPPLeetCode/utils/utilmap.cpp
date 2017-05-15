#include<iostream>
#include<unordered_map>
#include"util.h"
using namespace std;

template<class K, class V>
ostream& operator << (ostream& out, unordered_map<K, V>& map){
    for(typename unordered_map<K, V>::iterator iter = map.begin();
        iter != map.end(); ++iter){
        out << iter->first << ":" << iter->second <<endl;
    }
    return out;
}
