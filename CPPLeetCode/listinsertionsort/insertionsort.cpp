#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
        if(head==NULL) return NULL;
        for(ListNode * next =head->next;next!=NULL;)
        {
			for(ListNode *n2 =head,*pre = n2;n2!=next;)
			{
				if(n2->val<next->val)
				{
					n2->next = next->next;
					next->next = n2;
					if(n2!=head)
					pre->next = next;
					else
					head = next;
					ListNode * tmp = n2;
					n2 = next;
					next = tmp->next;
					break;
				}
				else
				{
					pre = n2;
					n2=n2->next;
				}
			}
        }
		return head;
    }
};
ListNode * mklink(int a[],int n)
{
	if(n<=0||a==NULL)return NULL;
	ListNode * head = new ListNode(a[0]);
	ListNode *tmp =head;
	for(int i=1;i<n;i++)
	{
		ListNode * node = new ListNode(a[i]);
		tmp->next = node;
		tmp = node;
	}
	return head;
}
void freelink(ListNode ** head)
{
	ListNode *next =*head,*pre = *head;
	for(;next!=NULL;)
	{
		next=next->next;
		delete pre;
		pre = next;
	}
	*head = NULL;
}
ostream & operator << (ostream & out ,ListNode * head)
{
	if(head==NULL) return out;
	for(ListNode * next = head;next!=NULL;next =next->next)
	out << next->val<<" ";
	return out;
}
int main()
{
	const int n =4;
	int a[n]={1,2,3,4};
	ListNode * head = mklink(a,n);
	Solution s;
	//head = s.insertionSortList(head);

	cout << head;
	freelink(&head);	
}