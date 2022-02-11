// ���������������ͷ�ڵ�?headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣�����������û�н��㣬���� null ��

// ͼʾ���������ڽڵ� c1 ��ʼ�ཻ��

// https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/


// ��������� ��
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
        bool flag = true; // true:����NULL false ���ҵ�����
        // cout << lenA << " " << lenB;

        // 2. ����
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

        // 3. ������same
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
// ��������¼������
// len + ���� + ������same
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

