// �����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����

// ʵ�� MyStack �ࣺ
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

    // void push(int x) ��Ԫ�� x ѹ��ջ����
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
    
    // int pop() �Ƴ�������ջ��Ԫ�ء�
    int pop() {
        int num = Queue.front();
        Queue.pop();
        return num;
    }
    
    // int top() ����ջ��Ԫ�ء�
    int top() {
        return Queue.front();
    }
    
    // boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
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
    cout << stack.top() << endl;  // ���� 2
    cout << stack.pop() << endl;   // ���� 2
    cout << stack.pop() << endl;   // ���� 1
    cout << stack.empty() << endl; // ���� true
    return 0;
}