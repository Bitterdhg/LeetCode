// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。
// 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

// 自解一：新string
// too simple

// 自解二：resize
// 将len变为两倍然后移动
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

// int main() {
//     string s = "lrloseumgh";
//     int k = 6;

//     //def
//     int len = s.length();
//     int left = 0;
//     int right = len - 1;

//     //1. 先将前面的刚在后面
//     s.resize(len * 2);
//     for (left = 0; left <= k - 1; left++) {
//         s[++right] = s[left];
//     }
//     // cout << s;

//     // 2. 前移
//     right = k - 1;
//     for (left = 0; left <= len - 1; left++) {
//         s[left] = s[++right];
//     }
//     s.resize(len);
//     cout << s;

//     return 0;
// }

// 自解三: 没有多余的空间浪费
// 反复前移 速度巨慢
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

// void forwardMove(string &s){
//     for (int i = 1; i < s.length(); i++) {
//         s[i-1] = s[i];
//     }
// }

// string reverseLeftWords(string s, int n) {
//     char tmp;
//     for (int i = 0; i < n; i++) {
//         tmp = s[0];
//         forwardMove(s);
//         s[s.length() - 1] = tmp;
//     }
//     return s;
// }

// int main() {
//     string s = "lrloseumgh";
//     int k = 6;
//     cout << reverseLeftWords(s, k);
//     return 0;
// }

// 法四: 题解的思路
// 与151. 颠倒字符串中的单词 有异曲同工之妙
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void reverseStr(string &s, int start, int end) {
    for (int i = 0; i < (end-start)/2; i++) {
        swap(s[start + i], s[(end-1) - i]);
    }
}

void reverseWord(string &s, int n){
    reverseStr(s, 0, s.length()-n); //cdefgba
    reverseStr(s, s.length()-n, s.length());
}

string reverseLeftWords(string s, int n) {
    reverseStr(s, 0, s.length());// gfedcba
    reverseWord(s, n);
    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;
    cout << reverseLeftWords(s, k);
    return 0;
}