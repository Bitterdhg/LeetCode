// ����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� 

# include <iostream>
# include <vector>
# include <algorithm>
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
		for(i = 0; i <= 7 ; i++) {
			ListNode* node=new ListNode;
			node->val= 7;
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
    //��������
	head->val=7;
	head->next=NULL;
	ll.createList(head);

    //����������
    // head = NULL;

    int val = 7;

    // def
    ListNode* cur;
    ListNode* last;

    // 0. add dummyHead
    ListNode* dummyHead = new ListNode;
    dummyHead -> next = head;

    // 2. begin
    if (head == NULL) ll.printList(head);
    cur = head;
    last = dummyHead;

    while (cur -> next != NULL) {
        // 1. val
        // 1.1 == val
        if (cur -> val == val) { 
            last -> next = cur -> next;
        } else {
            last = cur;
        }// if (cur -> val == val) 
        cur = cur -> next;
    }
    // 3. last
    if (cur -> val == val) {
        last -> next = NULL;
    }
    head = dummyHead -> next;
	ll.printList(head);
	return 0;
}

