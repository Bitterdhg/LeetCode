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

int main()
{
	ListNode* head=new ListNode;
	Solution ll;
    //创建链表
	head->val=7;
	head->next=NULL;
	ll.createList(head);

    //创建空链表
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

