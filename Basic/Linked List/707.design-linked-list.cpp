
// ��һ���������Խ�
// ��ǰ��� �� �м����� ��Ҫ����2��ϵ�� ��tail�ӣ���Ϊû��dummyTail ����ֻ��Ҫ����һ����ϵ

// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// class MyLinkedList {
// public:
// �����еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á�
// ��������ڵ�ṹ��
    // struct LinkNode {
    //     int val;
    //     LinkNode* next;
    //     LinkNode(int val) : val(val), next(NULL){} // ���캯��
    // };

// ��ʼ������
    // MyLinkedList() {
    //     _dummyHead = new LinkNode(0);
    //     _size = 0;
    // }

//��ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
    // void get(int index) { 
    //     LinkNode* tmp;
    //     tmp = _dummyHead;
    //     int i;
    //     if (index + 1 > _size) {
    //         // return -1;
    //         cout << -1 << endl;
    //         // delete tmp; // ��ôdelete
    //     }
    //     else {
    //         for (i = 0; i <= index; i++) {
    //             tmp = tmp -> next;
    //         } 
    //         // return tmp -> val;
    //         cout << tmp -> val << endl;
    //     } // if (index + 1 > _size)
    // }

// ������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
// Note:
// 1. �ȴ���newNode������
// 2. �ٴ���dummyNode
// 3��һ�������� _size
    // void addAtHead(int val) { 
    //     LinkNode * newNode = new LinkNode(val);
    //     newNode -> next = _dummyHead -> next;
    //     _dummyHead -> next = newNode; 
    //     _size++;
    // }

//��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
    // void addAtTail(int val) { 
    //     LinkNode * newNode = new LinkNode(val);
    //     LinkNode * tmp = _dummyHead;
    //     while (tmp -> next != NULL) {
    //         tmp = tmp -> next;
    //     }
    //     tmp -> next = newNode;
    //     _size++;
    // }

//�������еĵ�?index?���ڵ�֮ǰ���ֵΪ?val? �Ľڵ㡣���?index?��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ�
// Note:
// 1. ����
// 2. ��ӵ�ʱ��Ҳ��������
//  2.1 �ȴ��� `newNode` ������
//  2.2 ����ԭ����`Node` �� `newNode` �Ĺ�ϵ
//  2.3 `_size`
    // void addAtIndex(int index, int val) {
    //     if (index < 0) {
    //         addAtHead(val);
    //     }

    //     if ((index >= 0) && (index <= _size)) {
    //         LinkNode * newNode = new LinkNode(val);
    //         LinkNode * tmp = _dummyHead;
    //         int i;

    //         for (i = 0; i <= index - 1; i++) {
    //             tmp = tmp -> next;
    //         } 
    //         newNode -> next = tmp -> next;
    //         tmp -> next = newNode;
    //         _size++;
    //     }
    // }

 //������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣   
//     void deleteAtIndex(int index) {
//         if (index <= _size - 1) {
//             int i;
//             LinkNode * tmp = _dummyHead;

//             for (i = 0; i <= index - 1; i++) {
//                 tmp = tmp -> next;
//             } // tmp �� index - 1
//             tmp -> next = tmp -> next ->next;
//             _size--;
//         }
//     }

//     void printLinkList() {
//         LinkNode * cur = _dummyHead;
//         while (cur->next != NULL) {
//             cout << cur->next->val << " ";
//             cur = cur->next;
//         }
//         cout << endl;
//     }

// private:
//     int _size;
//     LinkNode * _dummyHead;
// };

// int main () {

//     MyLinkedList linkedList;
    //Test1:
    // linkedList.addAtHead(1);
    // linkedList.addAtTail(3);
    // linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
    // linkedList.get(1);            //����2
    // linkedList.deleteAtIndex(1);  //����������1-> 3
    // linkedList.get(1);            //����3

    //Test2:    
    // linkedList.addAtIndex(0,10);   //�����Ϊ10 
    // linkedList.addAtIndex(0,20);   //����20 -> 10 
    // linkedList.addAtIndex(1,30);   //����20 -> 30 ->10 
    // linkedList.get(0);            //����20

    // Test 3:
//     linkedList.addAtHead(9);   //�����Ϊ0
//     linkedList.get(1);         // -1
//     linkedList.addAtIndex(1,1); // 9,1
//     linkedList.addAtIndex(1,7); // 9 7 1
//     linkedList.deleteAtIndex(1); //9 1
//     linkedList.addAtHead(7); // 7 9 1
//     linkedList.addAtHead(4); // 4 7 9 1
//     linkedList.deleteAtIndex(1); // 4 9 1
//     linkedList.addAtIndex(1,4); // 4 4 9 1
//     linkedList.addAtHead(2); //2 4 4 9 1
//     linkedList.deleteAtIndex(5); //-1
//     linkedList.printLinkList();
// }

// // ["MyLinkedList","addAtHead","get","addAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtHead","deleteAtIndex"]
// // [[],[9],[1],[1,1],[1,7],[1],[7],[4], [1],[1,4],[2],[5]]


// Todo 2��˫������Խ�
// ��Ϊͷβ����dummyNode �����Ӷ���Ҫ���4����ϵ
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class MyLinkedList {
public:
// ����˫����
    struct LinkNode {
        int val;
        LinkNode * next;
        LinkNode * prev;
        LinkNode(int val):val(val), next(NULL), prev(NULL){}
    };

    // ��ʼ������
    MyLinkedList() {
        _dummyHead = new LinkNode(0); // ����ͷ�ڵ�
        _dummyTail = new LinkNode(0); // ����β�ڵ�
        _size = 0;
    }

    //��ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
    int get(int index) { 
        LinkNode* tmp = NULL;
        int i;

        // �Ƿ�Ϸ�
        if (index + 1 > _size || index < 0 ) { 
            cout << -1 << endl;
            return -1;
        } else { 
            // �������
            if (index <= (_size - 1) / 2) {
                tmp = _dummyHead; 
                for (i = 0; i <= index; i++) {
                    tmp = tmp -> next;
                } 
            // �������
            } else {
                tmp = _dummyTail;
                for (i = _size - 1; i >= index; i--) {
                    tmp = tmp -> prev;
                }
            }// if (index <= (_size - 1) / 2)
            cout << tmp -> val << endl;
            return 0;
        } // if (index + 1 > _size)
    }

    //������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
    // �뵥��������𣺻���Ҫ����prev 
    void addAtHead(int val) { 
        LinkNode * newNode = new LinkNode(val);
        if (_dummyHead -> next != NULL) {
            newNode -> next = _dummyHead -> next;
            newNode -> prev = _dummyHead; 
            _dummyHead -> next -> prev = newNode; // ����ߣ��ȳ���
            _dummyHead -> next = newNode;  // ����ߣ���̵�
        } else {
            newNode -> next = _dummyHead -> next;
            newNode -> prev = _dummyHead; 
            _dummyHead -> next = newNode;
            _dummyTail -> prev = newNode;
        }
        _size++;
    }

    //��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
    // �뵥��������𣺲���Ҫ��ͷ��ʼ������ֱ�Ӵ�β�Ϳ�ʼ����
    void addAtTail(int val) { 
        LinkNode * newNode = new LinkNode(val);
        if (_dummyTail -> prev != NULL) {
            newNode -> next = _dummyTail;
            newNode -> prev = _dummyTail -> prev;
            _dummyTail -> prev -> next = newNode; // ����ߣ��ȳ���
            _dummyTail -> prev = newNode; // ����ߣ���̵�
        } else {
            newNode -> next = _dummyTail;
            newNode -> prev = _dummyTail -> prev;
            _dummyHead -> next = newNode;
            _dummyTail -> prev = newNode;
        }
        _size++;
    }

    //�������еĵ�?index?���ڵ�֮ǰ���ֵΪ?val? �Ľڵ㡣���?index?��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ�
    void addAtIndex(int index, int val) {
        // index < 0
        if (index < 0) {
            addAtHead(val);
        }

        // 0 <= index <= _size
        // Todo !!!!!!������Ҫд���� �ж��Ƿ���_size / 2 ǰ��� ������� ��֮ ���������
        // ���� ��Ҫ���� 4 ���� newNode ��next��prev ��newNode��prev��next �� newNode��next��prev 
        if ((0 <= index) && (index <= _size)) {
            LinkNode * tmp = NULL;
            LinkNode * newNode = new LinkNode(val);
            int i = 0;

            // �������
            if (index <= (_size - 1) / 2) {
                tmp = _dummyHead; 
                for (i = 0; i <= index; i++) {
                    tmp = tmp -> next;
                } 
                // tmp �Ǳ��������һ��(next)
                newNode -> next = tmp;
                newNode -> prev = tmp -> prev;
                tmp -> prev -> next = newNode; // ��ȷ���Բ��ԣ�
                tmp -> prev = newNode;
            // �������
            } else {
                tmp = _dummyTail;
                for (i = _size - 1; i >= index; i--) {
                    tmp = tmp -> prev; // tmp��newNode����һ��(next)
                }
                // tmp �Ǳ��������һ��(next)
                newNode -> next = tmp;
                newNode -> prev = tmp -> prev;
                tmp -> prev -> next = newNode; // ��ȷ���Բ��ԣ�
                tmp -> prev = newNode;

            }// if (index <= (_size - 1) / 2)
            // cout << tmp -> val << endl;
            _size ++;
        }
    }

    //������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣   
    //Todo
    void deleteAtIndex(int index) {
        if (index <= _size - 1) {
            int i;
            LinkNode * tmp = NULL;
            // �������
            if (index <= (_size - 1) / 2) {
                tmp = _dummyHead; 
                for (i = 0; i <= index; i++) {
                    tmp = tmp -> next;
                } 
                tmp -> prev -> next = tmp -> next; // ��ȷ���Բ��ԣ�
                tmp -> next -> prev = tmp -> prev;
            // �������
            } else {
                tmp = _dummyTail;
                for (i = _size - 1; i >= index; i--) {
                    tmp = tmp -> prev; // tmp��newNode����һ��(next)
                }
                tmp -> prev -> next = tmp -> next; // ��ȷ���Բ��ԣ�
                tmp -> next -> prev = tmp -> prev;
            }// if (index <= (_size - 1) / 2)
            _size --;
            cout << tmp -> val << endl;
        }
    }

    void printLinkList() {
        LinkNode * cur = _dummyHead;
        while (cur -> next -> next != NULL) {
            cout << cur -> next -> val << " ";
            cur = cur -> next;
        }
        cur = cur -> next;
        cout << cur -> next -> val;
        cout << endl;
    }

private:
    int _size;
    LinkNode * _dummyHead;
    LinkNode * _dummyTail;
};
int main() {
    MyLinkedList linkedList;
    //Test1:
    linkedList.addAtHead(1);
    // linkedList.addAtTail(3);
    // linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
    // linkedList.get(1);            //����2
    linkedList.deleteAtIndex(0);  //����������1-> 3
    // linkedList.get(1);            //����3
    linkedList.printLinkList();
    return 0;
}