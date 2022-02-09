// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

// 思路1： swap函数 / 一个while循环 每次 i+=2 / 注意head 
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//定义结构体
struct ListNode{
	int val;
	ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数 这里没有分号
};

class Solution
{
public:
	/*创建单链表*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //不破坏头指针
		for(i = 2; i <= 7 ; i++) {
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

// swapEle函数 是将cur 与 a 进行swap
void swapEle (ListNode * pre, ListNode * cur) {
    // pre -> cur -> a -> b  //  pre ->  a -> cur -> b
    ListNode * temp = cur -> next;
    
    cur -> next = cur -> next -> next;
    temp -> next = cur;
    pre -> next = temp;
}

int main() {
    // ListNode * head = new ListNode(-1);
    ListNode * head = NULL;
	Solution ll;
    //创建链表
	// ll.createList(head);
	ll.printList(head);

    //def
    ListNode * dummyHead = new ListNode (-1);
    dummyHead -> next = head; 
    ListNode * temp = dummyHead;

    if (head == NULL || head -> next == NULL) {
        ll.printList(head);
        return 0;
    } else {
            head = head -> next;
            //------------------------------------------
            while (temp -> next != NULL &&  temp -> next -> next != NULL) {
                // swapEle (ListNode * pre, ListNode * cur) swapEle函数 是将cur 与 a 进行swap
                swapEle (temp , temp -> next);

                // update
                temp = temp -> next -> next;
            }
    }
    // -------------------------------------------
	// 	// out
	ll.printList(head);

    return 0;
}