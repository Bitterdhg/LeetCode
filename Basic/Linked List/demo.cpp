#include <iostream>
using namespace std;

//����ṹ��
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int val) : val(val), next(NULL){}
};


class Solution
{
public:
	/*����������*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //���ƻ�ͷָ��
		for(i=1;i<10;i++){
			ListNode* node=new ListNode (i);
			phead->next=node;
			phead=node;
		}
		cout<<"�������ɹ�!\n";
	}
	
	/*��ӡ����*/
	void printList(ListNode* head)
	{
		ListNode* phead=head;
		while(phead!=NULL)
		{
			cout<<phead->val<<" ";
			phead=phead->next;
		}
		cout<<"\n";
	}		
};


int main()
{
	ListNode* head=new ListNode (0);
	Solution ll;
	ll.createList(head);
	// ---------------------

	// ---------------------
	ll.printList(head);
	return 0;
}