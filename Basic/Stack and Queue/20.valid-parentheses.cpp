// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。



// - 犯的错误
//     - continue会跳过循环剩下的所有
//     - 这题没有考虑到”(” “)”这两种情况

// # include <iostream>
// # include <stack>         
// # include <vector>     
// # include <queue>       
// using namespace std;

// bool isValid(string s) {
//     bool res = true;
//     stack <char> Stack;
//     char tmp = ' ';
//     for (int i = 0; i < s.length(); i++) {
//         if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
//             Stack.push(s[i]);
//         } else {
//             if (Stack.empty() == true) {
//                 return false;
//             }
//             tmp = Stack.top();
//             if (s[i] == ')') {
//                 if (tmp != '(') {
//                     res = false;
//                     break;
//                 }
//             }
//             else if (s[i] == '}')
//             {
//                 if (tmp != '{') {
//                     res = false;
//                     break;
//                 }
//             }
//             else {
//                 if (tmp != '[') {
//                     res = false;
//                     break;
//                 } 
//             }
//             Stack.pop();
//         }
//     }
//     if (Stack.empty() != true) {
//         res = false;
//     }
//     return res;   
// }

// int main(){
//     string s = "(";
//     cout << isValid(s);
//     return 0;
// }


# include <iostream>
# include <stack>         
# include <vector>     
# include <queue>       
using namespace std;

bool isValid(string s) {
    stack <char> st;
    for (int i = 0; i < s.length(); i++) {
        // 接受的左边符号
        if (s[i] == '(') {
            st.push(')');
        }
        else if (s[i] == '{') {
            st.push('}');
        } 
        else if (s[i] == '[') {
            st.push(']');
        }
        // 接受的右边符号
        else if ((st.empty() != true) && st.top() == s[i]) {
            st.pop();
        }
        else return false;
    }
    return st.empty() == true ? true : false;
}

int main() {
    string s = "()";
    cout << isValid(s);
    return 0;
}