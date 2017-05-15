#ifndef UTILSLIST_H
#define UTILSLIST_H
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * MakeLink(int a[], int length);
void FreeLink(ListNode ** head);
ostream & operator << (ostream & out, ListNode * head);
#endif
