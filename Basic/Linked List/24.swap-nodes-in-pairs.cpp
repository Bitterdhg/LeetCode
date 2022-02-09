// ����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣
// ������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������

// ���룺head = [1,2,3,4]
// �����[2,1,4,3]

// ˼·1�� swap���� / һ��whileѭ�� ÿ�� i+=2 / ע��head 
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//����ṹ��
struct ListNode{
	int val;
	ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  // �ڵ�Ĺ��캯�� ����û�зֺ�
};

class Solution
{
public:
	/*����������*/
	void createList(ListNode *head)
	{
		int i;
		ListNode* phead=head; //���ƻ�ͷָ��
		for(i = 2; i <= 7 ; i++) {
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

// swapEle���� �ǽ�cur �� a ����swap
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
    //��������
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
                // swapEle (ListNode * pre, ListNode * cur) swapEle���� �ǽ�cur �� a ����swap
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