// 给定一个链表的头节点 ?head?，返回链表开始入环的第一个节点。?如果链表无环，则返回?null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

// 不允许修改 链表。

// #include <iostream>
// using namespace std;

// //定义结构体
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
// 		for(i=1;i<2;i++){
// 			ListNode* node=new ListNode (i);
// 			phead->next=node;
// 			phead=node;
// 		}
//         ListNode* node=new ListNode (2);
//         phead->next=node;
// 		node->next=head;
// 		cout<<"循环链表创建成功!\n";
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

// // 肯定有环
// // du -> 0 -> 1 -> 2

// int returnPos(ListNode *head) {
//     // def
//     ListNode * begin = head -> next; // 0
//     ListNode * temp = head -> next; // 0
//     ListNode * stdStemp = head -> next;
//     int pos = 0;
//     int num = 0;

//     for (pos = 0; pos <= 10000 - 1; pos ++) {
//         for (num = pos; num <= 10000 - 1; num ++) {
//             // case 1 huan nei 
//             if (temp -> next == begin) {
//                 return pos;
//             } else { // case 2 huan wai
//                 temp = temp -> next;
//                 continue;
//             }// if (temp -> next == begin)
//         }
//         begin = begin -> next;
//         stdStemp = stdStemp -> next;
//         temp = stdStemp;
//     }
//     return -1;
// }

// // 法一：暴力
// // 双指针比较next
// // 1. len (判断是否有环)

// int main()
// {
// 	ListNode* head=new ListNode (0);
// 	Solution ll;

// 	ll.createList(head);
// 	// ---------------------
//     // def
//     int len = 0;
//     int pos = -2;
//     ListNode * dummyHead = new ListNode (-1);
//     dummyHead -> next = head;

//     // 1. yes or no circle
//     while (head != NULL && len <= 10001) {
//         len++;
//         head = head -> next;
//     }

//     // 2. pos
//     if (len != 10002) {
//         pos = -1;
//     } else {
//         pos = returnPos(dummyHead);
//     } //if (len != 10002)
    
//     // 3. out
//     cout << pos;

// 	// ---------------------
// 	return 0;
// }


// 法二：双指针（很牛逼）

// 给定一个链表的头节点 ?head?，返回链表开始入环的第一个节点。?如果链表无环，则返回?null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

// 不允许修改 链表。

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
	/*创建循环链表*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //不破坏头指针
		for(i=1;i<2;i++){
			ListNode* node=new ListNode (i);
			phead->next=node;
			phead=node;
		}
        ListNode* node=new ListNode (2);
        phead->next=node;
		node->next=head;
		cout<<"循环链表创建成功!\n";
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
	ListNode* head=new ListNode (0);
	Solution ll;

	ll.createList(head);
	// ---------------------
    // def 
    ListNode * fastPointer = head;
    ListNode * slowPointer = head;
    ListNode * temp = head;

    // 善用while循环 而不是if语句！！！！
    while (fastPointer != NULL && fastPointer -> next != NULL) { // 重要！！！！！写入笔记
        fastPointer = fastPointer -> next -> next; // 重要！！！！！写入笔记
        slowPointer = slowPointer -> next; 
        if (fastPointer == slowPointer) {
            while (temp != slowPointer) {
                temp = temp -> next;
                slowPointer = slowPointer -> next;
            }
            ll.printList(temp);
        }
    }
    cout << NULL;
    // ---------------------
	return 0;
// 写的不好 对于while循环的运用还不是很熟练 足以代替if

    // if (fastPointer == NULL || fastPointer -> next == NULL) {
    //     cout << NULL;
    // } else {
    //     // 1. circle? fast +2 slow +1
    //     do {
    //         fastPointer = fastPointer -> next -> next;
    //         slowPointer = slowPointer -> next; 
    //     } while (fastPointer == slowPointer || fastPointer == NULL);

    //     if (fastPointer == NULL)
    //     // 2. x = z
    //     // circle Yes: temp starts at begin;  slow starts at jiaohui     + 1 


    //     // 3. out jiaohui head / NULL

    // }
}