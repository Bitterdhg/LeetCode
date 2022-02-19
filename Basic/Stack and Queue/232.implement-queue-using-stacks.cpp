//�����ʹ������ջʵ�������ȳ�����

// void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
// int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
// int peek() ���ض��п�ͷ��Ԫ��
// boolean empty() �������Ϊ�գ����� true �����򣬷��� false

// ���������˫stackģ��
// ��2��ջ���ֱ�������ջ ���ջ��Ȼ��������Ӧ�Ĳ���������ת��
# include <iostream>
# include <stack>         
# include <vector>     
# include <deque>       
using namespace std;

class MyQueue {
public:
    stack <int> inStack;
    stack <int> ouStack;

    // state ָ��ǰ״̬��
    // ����ջ ��true 
    // ���ջ�� false
    bool state = true;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // �����ջ��false״̬��
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
        // ������ջ��true״̬��
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
        // ���ջ ��״̬
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
    cout << queue.peek() << endl;  // ���� 1
    cout << queue.pop() << endl;   // ���� 1
    cout << queue.pop() << endl;   // ���� 2
    cout << queue.empty() << endl; // ���� true
    return 0;
}