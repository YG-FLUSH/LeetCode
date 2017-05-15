#include<iostream>
#include "utillist.h"
using namespace std;


ListNode * MakeLink(int a[], int length){
	if(length <= 0 || a == NULL) return NULL;

	ListNode * head = new ListNode(a[0]);
	ListNode *tmp = head;
    cout << length << " length " << endl;

	for(int i=1; i < length; ++i) {
		ListNode * node = new ListNode(a[i]);
		tmp->next = node;
		tmp = node;
	}
    tmp->next=NULL;
	return head;
}

void FreeLink(ListNode ** head){
	ListNode *next = *head, *pre = *head;
	for( ; next!=NULL; ){
		next=next->next;
		delete pre;
		pre = next;
	}
	*head = NULL;
}

ostream & operator << (ostream & out, ListNode * head)
{
	if(head==NULL) return out;

	for(ListNode * next=head; next!=NULL; next=next->next)
        out << next->val << " ";
	return out;
}


