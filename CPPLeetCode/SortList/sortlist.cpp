#include <iostream>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *sortList(ListNode *head) {
		return findmiddle(head);
    }
private:
	ListNode *	findmiddle(ListNode *head)
	{
	if(head ==NULL){return NULL;}
		ListNode *slowp=head,*fastp=head;
		while(fastp!=NULL)
		{
			fastp = fastp->next;
			if(fastp!=NULL){
			fastp = fastp->next;
			}
			slowp = slowp->next;	//找到中间点
		}
		findmiddle(head);
		findmiddle(slowp);
		return merge(head,slowp);
	}
	ListNode *merge(ListNode *lnd,ListNode *rnd)
	{
		ListNode *p,*head;
		if(lnd->val <=rnd->val)
		p=lnd,lnd=lnd->next,head=lnd;
		else
		p=rnd,rnd=rnd->next,head=rnd;
		while(lnd&&rnd)
		{
			if(lnd->val <=rnd->val)
			{
				p->next = rnd;
				p=lnd;
				lnd = lnd->next;
			}
			else
			{
				p->next = lnd;
				rnd = rnd->next;
				p=rnd;
			}
		}
		if(!lnd)
		{
			p->next =rnd;
		}
		else if(!rnd)
		{
			p->next = lnd;
		}
		return head;
	}
};
int main()
{
	Solution s;
	ListNode nod(0);
	s.sortList(&nod);
}