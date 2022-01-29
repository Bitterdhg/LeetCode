// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//定义结构体
struct ListNode{
	int val;
	ListNode* next;
};

class Solution
{
public:
	/*创建单链表*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //不破坏头指针
		for(i = 0; i <= 7 ; i++) {
			ListNode* node=new ListNode;
			node->val= 7;
			node->next=NULL;
			phead->next=node;
			phead=node;
		}
		cout<<"链表创建成功!\n";
	}
	
	/*打印链表*/
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
// 法一： 迭代法
// int main()
// {
// 	ListNode* head=new ListNode;
// 	Solution ll;
//     //创建链表
// 	head->val=4;
// 	head->next=NULL;
// 	ll.createList(head);
// 	ll.printList(head);
//     int val = 4;
// // ---------------------------
//     // def
// 	ListNode* dummyHead = new ListNode;      // 虚拟头指针
// 	dummyHead -> next = head;

// 	ListNode* bd = new ListNode;
// 	bd = dummyHead; // 在这个指针 以前即指针本身 都是ok的，后面的不确定

// 	ListNode* nex = new ListNode;

// 	// begin
// 	while (bd -> next != NULL) { // 确定链表不为空 且 没到最后一个！
// 		nex = bd -> next;
// 		if (nex -> val == val) { // 不ok nex改变
// 			bd -> next = nex -> next;
// 			delete nex;
// 		} else {
// 			bd = bd -> next; // 只有ok了 bd才会改变
// 		}
// 	}

// 	// out
// 	head = dummyHead -> next;
// 	ll.printList(head);
	
// // ---------------------------
// 	return 0;
// }


// 法二：递归
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
    //创建链表
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