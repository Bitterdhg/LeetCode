// 给你两个单链表的头节点?headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

// 图示两个链表在节点 c1 开始相交：

// https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/


// 启发于题解 ：
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

int lengthLink(ListNode * head) {
        int len = 0;

        while (head != NULL) {
            len ++;
            head = head -> next;
        }
        return len;
    }

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // def

        // 1. len
        int lenA = lengthLink(headA);
        int lenB = lengthLink(headB);
        int big = -1;
        int i = -1;
        bool flag = true; // true:返回NULL false ：找到交点
        // cout << lenA << " " << lenB;

        // 2. 对齐
        if (lenA > lenB) {
            for (i = 1; i <= lenA - lenB; i++) {
                headA = headA -> next;
            }
        } else {
            for (i = 1; i <= lenB - lenA; i++) {
                headB = headB -> next;
            }
        }//if (lenA > lenB) 
        // cout << headA -> val << " " << headB -> val;

        // 3. 遍历找same
        while (headA != NULL) {
            if (headA == headB) {
                flag = false;
                break;
            } else {
                headA = headA -> next;
                headB = headB -> next;
            }
        }

        if (flag) return NULL;
        else return headA; 
}
// 代码随想录的启发
// len + 对齐 + 遍历找same
int main()
{
	ListNode* headA=new ListNode (0);
	Solution ll;
	ll.createList(headA);
	ListNode * headB = new ListNode (-1);
	headB -> next = headA -> next;
	ListNode * result = NULL;

	// ---------------------
	result = getIntersectionNode (headA, headB);
	// ---------------------
	cout << "headA: ";
	ll.printList(headA);
	cout << endl;
	cout << "headB: ";
	ll.printList(headB);
	cout << endl;
	cout << "result: ";
	ll.printList(result);
	// ll.printList(headB);
	return 0;
}

