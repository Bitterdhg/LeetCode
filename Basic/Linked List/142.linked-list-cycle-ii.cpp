// ����һ�������ͷ�ڵ� ?head?����������ʼ�뻷�ĵ�һ���ڵ㡣?��������޻����򷵻�?null��

// �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
// Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
// ��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

// �������޸� ����

// #include <iostream>
// using namespace std;

// //����ṹ��
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
// 		for(i=1;i<2;i++){
// 			ListNode* node=new ListNode (i);
// 			phead->next=node;
// 			phead=node;
// 		}
//         ListNode* node=new ListNode (2);
//         phead->next=node;
// 		node->next=head;
// 		cout<<"ѭ���������ɹ�!\n";
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

// // �϶��л�
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

// // ��һ������
// // ˫ָ��Ƚ�next
// // 1. len (�ж��Ƿ��л�)

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


// ������˫ָ�루��ţ�ƣ�

// ����һ�������ͷ�ڵ� ?head?����������ʼ�뻷�ĵ�һ���ڵ㡣?��������޻����򷵻�?null��

// �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
// Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
// ��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

// �������޸� ����

#include <iostream>
using namespace std;

//����ṹ��
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int val) : val(val), next(NULL){}
};


class Solution
{
public:
	/*����ѭ������*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //���ƻ�ͷָ��
		for(i=1;i<2;i++){
			ListNode* node=new ListNode (i);
			phead->next=node;
			phead=node;
		}
        ListNode* node=new ListNode (2);
        phead->next=node;
		node->next=head;
		cout<<"ѭ���������ɹ�!\n";
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

    // ����whileѭ�� ������if��䣡������
    while (fastPointer != NULL && fastPointer -> next != NULL) { // ��Ҫ����������д��ʼ�
        fastPointer = fastPointer -> next -> next; // ��Ҫ����������д��ʼ�
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
// д�Ĳ��� ����whileѭ�������û����Ǻ����� ���Դ���if

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

