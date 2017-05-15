#include<iostream>
#include<vector>
#include"util.h"
#include<sstream>
using namespace std;

string split(string& str, char sperator, vector<string>& result){
    int j = 0;
    for(int i=0 ; i < str.length(); ++i){
        if(str[i] == sperator){
            result.push_back(str.substr(j, i-j));
            j = i+1;
        }
    }
    result.push_back(str.substr(j, str.length()));
    return str;
}

bool operator == (string& s1, string& s2){
    if(s1.length() != s2.length())
        return false;

    for(int i=0; i < s1.length(); ++i){
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

string IntToString(int n){
    stringstream result;
    result << n;
    return result.str();
}
