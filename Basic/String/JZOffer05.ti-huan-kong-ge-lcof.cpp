// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 输入：s = "We are happy."
// 输出："We%20are%20happy."

// 自解一：生成新的string
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string s = "We are happy.";

    // def
    string str;
    int length = s.length();
    int i = 0;
    int j = -1; // 指当前new str的尾巴的index
    // find     
    while (i <= length - 1) {
        if (s[i] == ' ') {
            str += "%20";
            i ++;
        } else {
            str += s[i];
            i++;
        } // if (s[i] == ' ')
    }
    cout << str;
    return 0;
}

