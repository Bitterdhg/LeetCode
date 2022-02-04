// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。
// 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

// 自解一：新string
// too simple

// 自解二：resize
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;



int main() {
    string s = "lrloseumgh";
    int k = 6;

    //def
    int len = s.length();
    int left = 0;
    int right = len - 1;

    //1. 先将前面的刚在后面
    s.resize(len * 2);
    for (left = 0; left <= k - 1; left++) {
        s[++right] = s[left];
    }
    // cout << s;

    // 2. 前移
    right = k - 1;
    for (left = 0; left <= len - 1; left++) {
        s[left] = s[++right];
    }
    s.resize(len);
    cout << s;

    return 0;
}