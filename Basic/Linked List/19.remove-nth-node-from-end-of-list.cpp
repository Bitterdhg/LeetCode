// ���룺head = [1], n = 1
// �����[]

// �Խ�һ������ɨһ��ȷ��len��Ȼ����ɨһ��ɾ��
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

//
ListNode* removeNthFromEnd(ListNode* head, int n, int len) {
    // len = 2 n = 1 
    int times = len - n;// +1 ��ԭ���� dummyhead ��ʼ
    ListNode * dummyHead = head;

    for (int i = 1; i <= times; i++){
        head = head -> next;
    }// ����pre
 
 // remove 1 -> 2 -> 3  1 -> 3      1 -> 2  1
    head -> next = head -> next -> next;
    return dummyHead -> next;
}

int main()
{
	ListNode* head=new ListNode (0);
	Solution ll;
	ll.createList(head);
    // ˼·�� ����������յ� �� remove����head
	// ---------------------

    // def 
    ListNode * dummyHead = new ListNode (-1);
    dummyHead -> next = head; 
    ListNode * temp =head;
    int len = 0;

    //1. len
    while (temp != NULL) {
        len ++;
        // update
        temp = temp -> next;
    }
    // cout << len << endl;

    // 2. remove
    if (head == NULL || head -> next == NULL) {
        cout << NULL << endl;
    } else {
        head = removeNthFromEnd(dummyHead, 2, len);
        ll.printList(head);
    }
    
	// ---------------------
	// ll.printList(head);
	return 0;
}

