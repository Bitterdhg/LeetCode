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
//     int hI = 0;// haystack 's first index
//     int nI = 0;// needle 's index
//     bool flag = true; // false: 不match true：match
//     // match
//     if (needle == "") {
//         cout << 0;
//         return 0;
//     } else {
//         for (hI = 0; hI <= lenH - lenN; hI++) {
//             flag = true;
//             for (nI = 0; nI <= lenN - 1; nI++) {
//                 if (haystack[hI + nI] != needle[nI]) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag) {
//                 cout << hI;
//                 return 0;
//             }
//         }
//         cout << -1;
//     }
    
//     return 0;
// }

// 自解二：KMP算法
// 整体右移，最左边填-1
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// 整体右移，最左边填-1
void getNext(int * next, string & s) {
    int prefix = -1; // -1 important 
    int suffix = 1;
    int len = s.length();

    next[0] = -1; 
    for (suffix = 1; suffix <= len - 1; suffix++) { 

        // 但第一个不满足条件的时候，加一个 prefix >= 0，然后从-1开始

        // 1. 去找到 公共前后缀
        while (prefix >= 0 && s[prefix + 1] != s[suffix]) { // + 1   important
            prefix = next[prefix];
        }
        // 2. 如果最后停下来的位置的元素 相等 ； 反之直接赋值为-1
        if(s[prefix + 1] == s[suffix]) {
            prefix++;
        }
        // whatever 2 cases need this sentences below
        next[suffix] = prefix;
    }
}

int main() {
    string haystack = "";
    string needle = "";
    
    //def
    int next[50001] = {};
    int hI = 0;
    int nI = -1;
    int lenH = haystack.length();
    int lenN = needle.length();

    // 0. 0
    if (needle == "") {
        cout << 0;
        return 0;
    } else {
    // 1. Next数组
        getNext(next, needle);
        // for (int i = 0; i <= 2; i++) {
        //     cout << next[i] <<" ";
        // }

    // 2. match
        // string haystack = "hello";
        // string needle = "ll";

        for (hI = 0; hI <= lenH - 1; hI++) {
            // 1. find 公共前后缀
            while (nI >= 0 && haystack[hI] != needle[nI + 1]) { // 不匹配
                nI = next[nI];
            }
            // 2. same
            if (haystack[hI] == needle[nI + 1] ) {  // 匹配，needI和hayI同时向后移动
                nI++; // 比较下一个位置 nI++ 不加hI因为 它自动都会加
            }

            // 3。 是否out
            if ((nI + 1) == lenN) {
                cout << hI - lenN + 1;
                return 0;
            }
        }
        cout << -1;
    }
    
    return 0;
}

// 总结：
//https://www.notion.so/KMP-28-strStr-24e15c169e61420989d7ad2d009add91#4a9b60aba59c4e4e8421cf7f91a48170