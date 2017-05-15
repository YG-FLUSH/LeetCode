#include<iostream>
#include <stdio.h>
#include"../utils/utillist.h"
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL)
            return;

        if(node->next == NULL){
            delete node;
            return;
        }

        ListNode *next = node->next;
        memcpy(node, next, sizeof(ListNode));
        delete next;
    }
};

int main(){
    int a[] = {1, 2, 3, 4};
    ListNode *head = MakeLink(a, sizeof(a)/sizeof(int));
    ListNode *del_node = head->next->next->next;
    Solution().deleteNode(del_node);
    cout << head;
}
