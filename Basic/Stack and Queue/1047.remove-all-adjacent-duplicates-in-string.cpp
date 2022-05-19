// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 S 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
// 自解
// # include <iostream>
// # include <algorithm> 
// # include <stack>         
// # include <vector>     
// # include <queue>       
// using namespace std;

// string removeDuplicates(string s) {
//     // "abbaca"
//     stack <char> st;
//     char top;
//     for (int i = 0; i < s.length() ; i++) {
//         // not empty!
//         if (st.empty() != true) {
//             top = st.top();
//             // new == top -> top pop
//             if (s[i] == top) {
//                 st.pop();
//             } else {
//                 st.push(s[i]);
//             }
//         // empty
//         } else {
//             st.push(s[i]);
//         }
//     }
//     string res;
//     while (st.empty() != true) {
//         res += st.top();
//         st.pop();
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }

// int main() {
//     string s = "abbaca";
//     cout << removeDuplicates(s);
//     return 0;
// }

// 看了题解后的题解
# include <iostream>
# include <algorithm> 
# include <stack>         
# include <vector>     
# include <queue>       
using namespace std;

string removeDuplicates(string s) {
    // "abbaca"
    stack <char> st;
    for (int i = 0; i < s.length(); i++) {
        if (st.empty() == true || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }

    string res;
    while (st.empty() != true) {
        res += st.top();
        st.pop();
    } 
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s);
    return 0;
}