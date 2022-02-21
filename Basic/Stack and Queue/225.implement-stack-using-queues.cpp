// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

// 实现 MyStack 类：
# include <iostream>
# include <stack>         
# include <vector>     
# include <queue>       
using namespace std;

class MyStack {
public:
    queue <int> tempQueue;
    queue <int> Queue;
    bool state = true;

    MyStack() {

    }

    // void push(int x) 将元素 x 压入栈顶。
    void push(int x) {
        // 1. push cur
        tempQueue.push(x);

        // 2. pre -> new
        while (Queue.empty() != true) {
            tempQueue.push(Queue.front());
            Queue.pop();
        }

        // 3. new -> pre
        while (tempQueue.empty() != true) {
            Queue.push(tempQueue.front());
            tempQueue.pop();
        }
    }
    
    // int pop() 移除并返回栈顶元素。
    int pop() {
        int num = Queue.front();
        Queue.pop();
        return num;
    }
    
    // int top() 返回栈顶元素。
    int top() {
        return Queue.front();
    }
    
    // boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
    bool empty() {
        if (Queue.empty() == true) {
            return true;
        } else {
            return false;
        }
    }
};

int main (){
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;  // 返回 2
    cout << stack.pop() << endl;   // 返回 2
    cout << stack.pop() << endl;   // 返回 1
    cout << stack.empty() << endl; // 返回 true
    return 0;
}