// ���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
// ���룺head = [1,2,3, 4,5]���ѷ�ת����δ��תList��
// �����[5,4, 3,2,1]��δ��תList�����ѷ�ת��

// �ο��𰸵�
// ˫ָ��
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode * next;
// 	ListNode(int val) : val(val), next(NULL){}
// };

// class Solution
// {
// public:
// 	/*����������*/
// 	void createList(ListNode *head)
// 	{
// 		int i;
// 		ListNode* phead=head; //���ƻ�ͷָ��
// 		for(i=1;i<10;i++){
// 			ListNode* node=new ListNode (i);
// 			phead->next=node;
// 			phead=node;
// 		}
// 		cout<<"�������ɹ�!\n";
// 	}
	
// 	/*��ӡ����*/
// 	void printList(ListNode* head)
// 	{
// 		ListNode* phead=head;
// 		while(phead!=NULL)
// 		{
// 			cout<<phead->val<<" ";
// 			phead=phead->next;
// 		}
// 		cout<<"\n";
// 	}		
// };

// int main() {
// 	ListNode* head=new ListNode (0);
// 	Solution ll;
// 	ll.createList(head);
//     ll.printList(head);
//     cout << endl;
// // //---------------------

// 	//def
// 	ListNode * fastPointer = head;
// 	ListNode * slowPointer = NULL;
// 	ListNode * tmp;
// 	// iter
// 	while (fastPointer != NULL) { // ����Ϳ��жϵ�ǰԪ���Ƿ���Դ����Ͳ��õ����ó������һ��Ԫ���ˣ�����
// 		// fastPointer �Ǳ�����Ԫ��
// 		tmp = fastPointer -> next; // ����fastPointer����һ��Ԫ�� �Ա�����update 
// 		// slow  <- fast 
// 		fastPointer -> next = slowPointer;
	
// 		// update
// 		slowPointer = fastPointer;
// 		fastPointer =  tmp;
// 	} // �˳�ʱ fastPointer ��NULL
// 	// out
// 	ll.printList(slowPointer); //  �˳�ʱ fastPointer ��NULL �������slowPointer


// 	return 0;
// }

// // �ο��𰸵�
// // ˫ָ��
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode * next;
// 	ListNode(int val) : val(val), next(NULL){}
// };

// class Solution
// {
// public:
// 	/*����������*/
// 	void createList(ListNode *head)
// 	{
// 		int i;
// 		ListNode* phead=head; //���ƻ�ͷָ��
// 		for(i=1;i<10;i++){
// 			ListNode* node=new ListNode (i);
// 			phead->next=node;
// 			phead=node;
// 		}
// 		cout<<"�������ɹ�!\n";
// 	}
	
// 	/*��ӡ����*/
// 	void printList(ListNode* head)
// 	{
// 		ListNode* phead=head;
// 		while(phead!=NULL)
// 		{
// 			cout<<phead->val<<" ";
// 			phead=phead->next;
// 		}
// 		cout<<"\n";
// 	}		
// };



// �������ݹ� 
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

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

// 1 <- 2 <- 3 ��reve��   ��left��4  
// �Ҹо�����β�ݹ飬��ȷ��
ListNode * reverse (ListNode * left, ListNode * reve) {
	if (left == NULL) { // leftûʣ��Ԫ����
		return reve;
	} else { //reverse opration
		ListNode * tmp = left -> next;
		left -> next = reve;
		// update 
		reve = left;
		left = tmp;
		return reverse (left, reve);
	} //if (left == NULL)
}

int main() {
	ListNode* head=new ListNode (0);
	Solution ll;
	ll.createList(head);
    ll.printList(head);
    cout << endl;
// //---------------------

	//def
	ListNode * left = head;
	ListNode * reve = NULL;
	ListNode * result = NULL;
	// recur
	// ˼�������������� �Ѿ���ת123�� ������Ҫ��ת4 
	//  1 <- 2 <- 3 ��slowPointer��   ��fastPointer��4  
	// void reverse (ListNode * left, ListNode * reve)
	result = reverse (left, reve);
	// out
	ll.printList(result); //  �˳�ʱ fastPointer ��NULL �������slowPointer
	return 0;
}

// �Խ�1������
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

// struct ListNode{
// 	int val;
// 	ListNode* next;
// };
 
// class Solution
// {
// public:
// 	/*����������*/
// 	void createList(ListNode *head)
// 	{
// 		int i;
// 		ListNode* phead=head; //���ƻ�ͷָ��
// 		for(i=1;i<10;i++){
// 			ListNode* node=new ListNode;
// 			node->val=i;
// 			node->next=NULL;
// 			phead->next=node;
// 			phead=node;
// 		}
// 		cout<<"�������ɹ�!\n";
// 	}
	
// 	/*��ӡ����*/
// 	void printList(ListNode* head)
// 	{
// 		ListNode* phead=head;s
// 		while(phead!=NULL)
// 		{
// 			cout<<phead->val<<" ";
// 			phead=phead->next;
// 		}
// 		cout<<"\n";
// 	}		
// };

// int main()
// {
// 	ListNode* head=new ListNode;
// 	Solution ll;
// 	head->val=0;
// 	head->next=NULL;
// 	ll.createList(head);
//     ll.printList(head);
//     cout << endl;
// //---------------------
//     //def
//     ListNode * dummyNodeOld = new ListNode; // ����֮�أ���
//     dummyNodeOld -> next = head;
//     ListNode * dummyNodeNew = new ListNode; // ����֮�أ���
//     dummyNodeNew -> val = 0;
//     dummyNodeNew -> next = NULL;
//     ListNode * newNode;
//     ListNode * nextOld;
//     // 2. reverse
//     // 2.1 δ��ת��head ���� �Ѿ���ת��ǰ��
//     while (dummyNodeOld -> next != NULL) {
//         // 2.1.1 ���´�dummyNodeOld�ĵ���Ԫ�ر�������
//         nextOld = dummyNodeOld -> next -> next;
//         newNode = dummyNodeOld -> next;
//         // 2.1.2 ���� �Ѿ���ת�� ǰ��
//         newNode -> next = dummyNodeNew -> next;
//         dummyNodeNew -> next = newNode;
//         // 2.1.3 update 
//         dummyNodeOld -> next = nextOld;
//     }
// //---------------------
// 	ll.printList(dummyNodeNew -> next);
// 	return 0;
// }



