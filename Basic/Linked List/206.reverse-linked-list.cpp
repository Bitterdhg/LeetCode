// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
// 输入：head = [1,2,3, 4,5]（已反转）（未反转List）
// 输出：[5,4, 3,2,1]（未反转List）（已反转）

// 参考答案的
// 双指针
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
// 	/*创建单链表*/
// 	void createList(ListNode *head)
// 	{
// 		int i;
// 		ListNode* phead=head; //不破坏头指针
// 		for(i=1;i<10;i++){
// 			ListNode* node=new ListNode (i);
// 			phead->next=node;
// 			phead=node;
// 		}
// 		cout<<"链表创建成功!\n";
// 	}
	
// 	/*打印链表*/
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
// 	while (fastPointer != NULL) { // 这里就可判断当前元素是否可以处理，就不用单独拿出来最后一个元素了！！！
// 		// fastPointer 是被操作元素
// 		tmp = fastPointer -> next; // 保存fastPointer的下一个元素 以便下面update 
// 		// slow  <- fast 
// 		fastPointer -> next = slowPointer;
	
// 		// update
// 		slowPointer = fastPointer;
// 		fastPointer =  tmp;
// 	} // 退出时 fastPointer 是NULL
// 	// out
// 	ll.printList(slowPointer); //  退出时 fastPointer 是NULL 所以输出slowPointer


// 	return 0;
// }

// // 参考答案的
// // 双指针
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
// 	/*创建单链表*/
// 	void createList(ListNode *head)
// 	{
// 		int i;
// 		ListNode* phead=head; //不破坏头指针
// 		for(i=1;i<10;i++){
// 			ListNode* node=new ListNode (i);
// 			phead->next=node;
// 			phead=node;
// 		}
// 		cout<<"链表创建成功!\n";
// 	}
	
// 	/*打印链表*/
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



// 法二：递归 
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

// 1 <- 2 <- 3 （reve）   （left）4  
// 我感觉这是尾递归，不确定
ListNode * reverse (ListNode * left, ListNode * reve) {
	if (left == NULL) { // left没剩下元素了
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
	ListNode* head = new ListNode (0);
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
	// 思考：分析：假设 已经翻转123了 现在需要反转4 
	//  1 <- 2 <- 3 （slowPointer）   （fastPointer）4  
	// void reverse (ListNode * left, ListNode * reve)
	result = reverse (left, reve);
	// out
	ll.printList(result); //  退出时 fastPointer 是NULL 所以输出slowPointer
	return 0;
}

// 自解1：迭代
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
// 	/*创建单链表*/
// 	void createList(ListNode *head)
// 	{
// 		int i;
// 		ListNode* phead=head; //不破坏头指针
// 		for(i=1;i<10;i++){
// 			ListNode* node=new ListNode;
// 			node->val=i;
// 			node->next=NULL;
// 			phead->next=node;
// 			phead=node;
// 		}
// 		cout<<"链表创建成功!\n";
// 	}
	
// 	/*打印链表*/
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
//     ListNode * dummyNodeOld = new ListNode; // 重中之重！！
//     dummyNodeOld -> next = head;
//     ListNode * dummyNodeNew = new ListNode; // 重中之重！！
//     dummyNodeNew -> val = 0;
//     dummyNodeNew -> next = NULL;
//     ListNode * newNode;
//     ListNode * nextOld;
//     // 2. reverse
//     // 2.1 未反转的head 放在 已经反转的前面
//     while (dummyNodeOld -> next != NULL) {
//         // 2.1.1 将下次dummyNodeOld的迭代元素保存下来
//         nextOld = dummyNodeOld -> next -> next;
//         newNode = dummyNodeOld -> next;
//         // 2.1.2 放在 已经反转的 前面
//         newNode -> next = dummyNodeNew -> next;
//         dummyNodeNew -> next = newNode;
//         // 2.1.3 update 
//         dummyNodeOld -> next = nextOld;
//     }
// //---------------------
// 	ll.printList(dummyNodeNew -> next);
// 	return 0;
// }



