//请你仅使用两个栈实现先入先出队列

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

// 题解启发：双stack模拟
// 有2个栈（分别是输入栈 输出栈）然后随着相应的操作，来回转化
# include <iostream>
# include <stack>         
# include <vector>     
# include <deque>       
using namespace std;

class MyQueue {
public:
    stack <int> inStack;
    stack <int> ouStack;

    // state 指当前状态：
    // 输入栈 ：true 
    // 输出栈： false
    bool state = true;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // 是输出栈（false状态）
        // convert
        if (!state) {
            while (!ouStack.empty()) {
                inStack.push (ouStack.top());
                ouStack.pop();
            }
            state = true;
        }
        
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 是输入栈（true状态）
        // convert
        if (state) {
            while (!inStack.empty()) {
                ouStack.push (inStack.top());
                inStack.pop();
            }
            state = false;
        }

        int num = ouStack.top();
        ouStack.pop();
        return num;   
    }

    /** Get the front element. */
    int peek() {
        int num = this -> pop();
        // 输出栈 的状态
        ouStack.push(num);
        return num;
    }
    
    bool empty() {
        if (inStack.empty() && ouStack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main (){
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // 返回 1
    cout << queue.pop() << endl;   // 返回 1
    cout << queue.pop() << endl;   // 返回 2
    cout << queue.empty() << endl; // 返回 true
    return 0;
}