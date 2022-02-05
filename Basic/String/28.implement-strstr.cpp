// 实现?strStr()?函数。

// 给你两个字符串?haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
// 如果不存在，则返回? -1 。

// 自解一：模拟
// 时间复杂度：O(n*m) n:haystack.length() m: needle.length()
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// int main() {
    

//     string haystack = "mississippia";
//     string needle = "issip";

//     //def
//     int lenH = haystack.length();
//     int lenN = needle.length();
//     int i = 0;
//     int j = 0; // haystack
//     int result = -1;

//     // needle = NULL
//     if (needle == "") cout << 0;
//     else {
//         // find 1st letter of needle
        
//         while (true) {
//             j = result;
//             while (j <= lenH - 1 && haystack[++j] != needle[0]); // 从左到右判断 这里会overstack!!!
//                 // j stop 在第一个相同的letter
//             if (j == lenH) {
//                 cout << -1;
//                 return 0;
//             } else { 
//                 result = j;
//                 // j--;
//                 i = 0;
//                 // find left letter of needle
//                 // j haystack
//                 while (haystack[++j] == needle[++i] && j <= lenH - 1);
//                 if (i == lenN) {
//                     cout << result;
//                     return 0;
//                 }
//                 else continue;
//             } //if (j == lenH)
//         }
//     }

//     return 0;
// }

// 题解二：Brute-Force算法 （标准暴力）
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string haystack = "mississippia";
    string needle = "issip";
    
    //def
    int lenH = haystack.length();
    int lenN = needle.length();
    int hI = 0;// haystack 's first index
    int nI = 0;// needle 's index
    bool flag = true; // false: 不match true：match
    // match
    if (needle == "") {
        cout << 0;
        return 0;
    } else {
        for (hI = 0; hI <= lenH - lenN; hI++) {
            flag = true;
            for (nI = 0; nI <= lenN - 1; nI++) {
                if (haystack[hI + nI] != needle[nI]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << hI;
                return 0;
            }
        }
        cout << -1;
    }
    
    return 0;
}