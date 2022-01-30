// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
// 输入：head = [1,2,3, 4,5]（已反转）（未反转List）
// 输出：[5,4, 3,2,1]（未反转List）（已反转）

// 自解1：迭代
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

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
		for(i=1;i<10;i++){
			ListNode* node=new ListNode;
			node->val=i;
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
	head->val=0;
	head->next=NULL;
	ll.createList(head);
    ll.printList(head);
    cout << endl;
//---------------------
    //def
    ListNode * dummyNodeOld = new ListNode; // 重中之重！！
    dummyNodeOld -> next = head;
    ListNode * dummyNodeNew = new ListNode; // 重中之重！！
    dummyNodeNew -> val = 0;
    dummyNodeNew -> next = NULL;
    ListNode * newNode;
    ListNode * nextOld;
    // 2. reverse
    // 2.1 未反转的head 放在 已经反转的前面
    while (dummyNodeOld -> next != NULL) {
        // 2.1.1 将下次dummyNodeOld的迭代元素保存下来
        nextOld = dummyNodeOld -> next -> next;
        newNode = dummyNodeOld -> next;
        // 2.1.2 放在 已经反转的 前面
        newNode -> next = dummyNodeNew -> next;
        dummyNodeNew -> next = newNode;
        // 2.1.3 update 
        dummyNodeOld -> next = nextOld;
    }
//---------------------
	ll.printList(dummyNodeNew -> next);
	return 0;
}

// 自解2：递归
// 分析：假设 已经翻转123了 现在需要反转4 
// 怎么做哇，就是将4放到 head（3）的前面即可