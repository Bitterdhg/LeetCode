// 根据 逆波兰表示法，求表达式的值。

// 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

// 注意 两个整数之间的除法只保留整数部分。

// 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
// 链接：https://leetcode.cn/problems/evaluate-reverse-polish-notation

# include <iostream>
# include <stack>         
# include <vector>     
# include <queue>       
using namespace std;
// leetcode 版本
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int res = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < tokens.size(); i++) {
            // symbol
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                y = st.top();
                st.pop();
                x = st.top();
                st.pop();

                if (tokens[i] == "+") {res = x+y;}
                else if (tokens[i] == "-") {res = x-y;}
                else if (tokens[i] == "*") {res = x*y;}
                else {res = x/y;}
                
                st.push(res);
            } else { // digit
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};