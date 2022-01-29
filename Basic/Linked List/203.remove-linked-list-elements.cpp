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
// ��һ�� ������
// int main()
// {
// 	ListNode* head=new ListNode;
// 	Solution ll;
//     //��������
// 	head->val=4;
// 	head->next=NULL;
// 	ll.createList(head);
// 	ll.printList(head);
//     int val = 4;
// // ---------------------------
//     // def
// 	ListNode* dummyHead = new ListNode;      // ����ͷָ��
// 	dummyHead -> next = head;

// 	ListNode* bd = new ListNode;
// 	bd = dummyHead; // �����ָ�� ��ǰ��ָ�뱾�� ����ok�ģ�����Ĳ�ȷ��

// 	ListNode* nex = new ListNode;

// 	// begin
// 	while (bd -> next != NULL) { // ȷ������Ϊ�� �� û�����һ����
// 		nex = bd -> next;
// 		if (nex -> val == val) { // ��ok nex�ı�
// 			bd -> next = nex -> next;
// 			delete nex;
// 		} else {
// 			bd = bd -> next; // ֻ��ok�� bd�Ż�ı�
// 		}
// 	}

// 	// out
// 	head = dummyHead -> next;
// 	ll.printList(head);
	
// // ---------------------------
// 	return 0;
// }


// �������ݹ�
ListNode* removeElement (ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	} else {
		if (head -> val == val) {
			head -> next = removeElement (head -> next, val);
			return head -> next;
		} else {
			head -> next = removeElement (head -> next, val);
			return head;
		} //if (head -> val == val)
		// head -> next = removeElement (head -> next, val);
	} //if (head == NULL)
}
int main() {
	ListNode* head=new ListNode;
	Solution ll;
    //��������
	head->val=7;
	head->next=NULL;
	ll.createList(head);
	ll.printList(head);
    int val = 7;
	//------------------------------------------
	head = removeElement (head, val);
	// 	// out
	ll.printList(head);
	
// ---------------------------
	return 0;

}