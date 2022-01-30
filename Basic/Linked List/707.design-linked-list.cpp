# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
// 法一：单链表自解
class MyLinkedList {
public:
// 链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
// 定义链表节点结构体
    struct LinkNode {
        int val;
        LinkNode* next;
        LinkNode(int val) : val(val), next(NULL){} // 构造函数
    };

// 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkNode(0);
        _size = 0;
    }

//获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    void get(int index) { 
        LinkNode* tmp;
        tmp = _dummyHead;
        int i;
        if (index + 1 > _size) {
            // return -1;
            cout << -1 << endl;
            // delete tmp; // 怎么delete
        }
        else {
            for (i = 0; i <= index; i++) {
                tmp = tmp -> next;
            } 
            // return tmp -> val;
            cout << tmp -> val << endl;
        } // if (index + 1 > _size)
    }

// 在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    void addAtHead(int val) { 
        LinkNode * newNode = new LinkNode(val);
        newNode -> next = _dummyHead -> next;
        _dummyHead -> next = newNode; 
        _size++;
    }

//将值为 val 的节点追加到链表的最后一个元素。
    void addAtTail(int val) { 
        LinkNode * newNode = new LinkNode(val);
        LinkNode * tmp = _dummyHead;
        while (tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = newNode;
        _size++;
    }

//在链表中的第?index?个节点之前添加值为?val? 的节点。如果?index?等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if (index < 0) {
            addAtHead(val);
        }
        if ((index >= 0) && (index <= _size)) {
            LinkNode * newNode = new LinkNode(val);
            LinkNode * tmp = _dummyHead;
            int i;

            for (i = 0; i <= index - 1; i++) {
                tmp = tmp -> next;
            } 
            newNode -> next = tmp -> next;
            tmp -> next = newNode;
            _size++;
        }
    }

 //如果索引 index 有效，则删除链表中的第 index 个节点。   
    void deleteAtIndex(int index) {
        if (index <= _size - 1) {
            int i;
            LinkNode * tmp = _dummyHead;

            for (i = 0; i <= index - 1; i++) {
                tmp = tmp -> next;
            } // tmp 是 index - 1
            tmp -> next = tmp -> next ->next;
            _size--;
        }
    }

    void printLinkList() {
        LinkNode * cur = _dummyHead;
        while (cur->next != NULL) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkNode * _dummyHead;
};

int main () {

    MyLinkedList linkedList;
    //Test1:
    // linkedList.addAtHead(1);
    // linkedList.addAtTail(3);
    // linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    // linkedList.get(1);            //返回2
    // linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    // linkedList.get(1);            //返回3

    //Test2:    
    // linkedList.addAtIndex(0,10);   //链表变为10 
    // linkedList.addAtIndex(0,20);   //返回20 -> 10 
    // linkedList.addAtIndex(1,30);   //返回20 -> 30 ->10 
    // linkedList.get(0);            //返回20

    // Test 3:
    linkedList.addAtHead(9);   //链表变为0
    linkedList.get(1);         // -1
    linkedList.addAtIndex(1,1); // 9,1
    linkedList.addAtIndex(1,7); // 9 7 1
    linkedList.deleteAtIndex(1); //9 1
    linkedList.addAtHead(7); // 7 9 1
    linkedList.addAtHead(4); // 4 7 9 1
    linkedList.deleteAtIndex(1); // 4 9 1
    linkedList.addAtIndex(1,4); // 4 4 9 1
    linkedList.addAtHead(2); //2 4 4 9 1
    linkedList.deleteAtIndex(5); //-1
    linkedList.printLinkList();
}

// // ["MyLinkedList","addAtHead","get","addAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtHead","deleteAtIndex"]
// // [[],[9],[1],[1,1],[1,7],[1],[7],[4], [1],[1,4],[2],[5]]

// Todo 1: 单链表的标答

// Todo 2：双链表的自解

// Todo 3: 双链表的标答