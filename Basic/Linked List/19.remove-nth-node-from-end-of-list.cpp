// 输入：head = [1], n = 1
// 输出：[]

// 自解一：可以扫一遍确定len，然后再扫一遍删除
#include <iostream>
using namespace std;

//定义结构体
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int val) : val(val), next(NULL){}
};


class Solution
{
public:
	/*创建单链表*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //不破坏头指针
		for(i=1;i<10;i++){
			ListNode* node=new ListNode (i);
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

//
ListNode* removeNthFromEnd(ListNode* head, int n, int len) {
    // len = 2 n = 1 
    int times = len - n;// +1 的原因是 dummyhead 开始
    ListNode * dummyHead = head;

    for (int i = 1; i <= times; i++){
        head = head -> next;
    }// 到达pre
 
 // remove 1 -> 2 -> 3  1 -> 3      1 -> 2  1
    head -> next = head -> next -> next;
    return dummyHead -> next;
}

int main()
{
	ListNode* head=new ListNode (0);
	Solution ll;
	ll.createList(head);
    // 思路： 特殊情况：空的 ； remove的是head
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

