#include <iostream>
using namespace std;

//����ṹ��
struct ListNode{
	int val;
	ListNode* next;
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
			ListNode* node=new ListNode;
			node->val=i;
			node->next=NULL;
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
	ListNode* head=new ListNode;
	Solution ll;
	head->val=0;
	head->next=NULL;
	ll.createList(head);
	ll.printList(head);
	return 0;
}

