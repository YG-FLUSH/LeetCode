#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /*�����ײ�*/
		ListNode* next ;
        ListNode* h = head;
        while(h!=NULL){
            if(h->val==val){
                ListNode* tmp = h;
                h = h->next;
                free(tmp);
            }
            else{
                break;
            }
        }
        ListNode* now = h;
        ListNode* nhead = h;
        if(now!=NULL){
            next = now->next;
        }
        else{
            return NULL;
        }
        /*�����в�*/
        while(next!=NULL){
            if(next->val == val){
                free(next);
                next = next->next;	//ǰ��ָ����ǰ�ƶ�
				now->next = next;	//��ǰָ���޸�next
            }
			else{
				now = next;
				next = next->next;
			}
        }
        return nhead;
    }
};

ListNode * mklink(int a[],int n)
{
	if(n<=0||a==NULL)return NULL;
	ListNode *head = new ListNode(a[0]);
	ListNode *tmp = head;
	for(int i=1;i<n;i++)
	{
		ListNode *node = new ListNode(a[i]);
		tmp->next = node;
		tmp = node;
	}
	return head;
}
void showlist(ListNode *head)
{	
	ListNode* n = head; 
	while(n != NULL)
	{
		cout << n->val << endl;
		n = n->next;
	}
}
int main()
{
	Solution s;
	const int n=4;
	int a[n]={1,2,2,1};
	ListNode *head = mklink(a,n);
	showlist(head);
	ListNode* lit = s.removeElements(head, 2);
	showlist(lit);
}