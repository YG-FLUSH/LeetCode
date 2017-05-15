#include<iostream>
#include "../utils/utillist.h"
using namespace std;

class Solution{
    public:
        ListNode* oddEvenList(ListNode *head){

            if(head == NULL || head->next == NULL)
                return head;

            ListNode *oddhead = head;
            ListNode *oddtail = oddhead;

            ListNode *evenhead = oddhead->next;
            ListNode *eventail = oddhead->next;

            ListNode *temp = eventail->next;

            int i = 3; // temp is the second Node
            while(temp != NULL){
                if(i%2 == 0){
                    // even link
                    eventail->next = temp;
                    eventail = temp;
                }
                else{
                    // odd link
                    oddtail->next = temp;
                    oddtail = temp;
                }
                temp = temp->next;
                ++i;
            }
            oddtail->next = evenhead;
            eventail->next = NULL;

            return oddhead;
        }

};

int main(){
    int a[] = {1, 2, 3, 4, 5};
    ListNode* head = MakeLink(a, sizeof(a)/sizeof(int));
    cout << head << endl;
    cout << Solution().oddEvenList(head) << endl;
    FreeLink(&head);

}

