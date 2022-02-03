// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 输入：s = "We are happy."
// 输出："We%20are%20happy."

// 自解一：生成新的string
// 时间复杂度：O(n) 空间复杂度O（n）

// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// int main() {
//     string s = "We are happy.";

//     // def
//     string str;
//     int length = s.length();
//     int i = 0;
//     int j = -1; // 指当前new str的尾巴的index
//     // find     
//     while (i <= length - 1) {
//         if (s[i] == ' ') {
//             str += "%20";
//             i ++;
//         } else {
//             str += s[i];
//             i++;
//         } // if (s[i] == ' ')
//     }
//     cout << str;
//     return 0;
// }


// 看了题解后的思路：法二：双指针
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string s = "We are happy.";

    // def
    int length = s.length();
    int leftPointer = length - 1; // 当前遍历的元素
    int rightPointer = 3 * length - 1; // 当前被遍历的元素应该放的位置的第三个
    int i;

    // 倒着来
    s.resize(3 * length);
    for (; leftPointer >= 0; leftPointer--) {// 左指针到达Tail 结束
         if (s[leftPointer] == ' ') {
             s[rightPointer--] = '0';
             s[rightPointer--] = '2';
             s[rightPointer--] = '%';
         } else {
            s[rightPointer--] = s[leftPointer];
         } // if (s[leftPointer] == ' ') 
    }

    for (i = rightPointer + 1; i <= 3 * length - 1; i++) {
        cout << s[i];
    }
    
    return 0;
}

