#ifndef UTIL_H
#define UTIL_H
#include"utillist.h"
#include<vector>
#include<unordered_map>
using namespace std;

string split(string& str, char sperator, vector<string>& result);
bool operator == (string& s1, string& s2);

template<class K, class V>
ostream& operator << (ostream& out, unordered_map<K, V>& map);
string IntToString(int n );
#endif

