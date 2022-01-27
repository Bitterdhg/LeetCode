// 有一个由小写字母组成的字符串 S，和一个整数数组 shifts。

// 我们将字母表中的下一个字母称为原字母的 移位（由于字母表是环绕的， 'z'?将会变成?'a'）

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
// 自己写的题解
// int main() {
//         // 分析： 第0个字母右移动次数（后迷案的数字所有加起来 % 26）
//         // 即：第 i 个字母右移动次数是 （i的后缀和 % 26 ）
//     vector <int> shifts {3,5,9};
//     string s = "abc";
//     // def
//     int length = shifts.size();
//     int upbd = length - 1;
//     int strlen = s.length();
//     int i;
//     int sign = 0;
//     int times = 0;
//     vector <long> sum(length + 1);
    
//     sum[upbd] = shifts[upbd];
//     // 1. 后缀和
//     for (i = upbd - 1; i >= 0; i--) { // sum[i] 指第i即i后面的数字的后缀和
//         sum[i] = sum[i + 1] + shifts[i];
//     } // sum[] = 17 14 9 
//     // for (i = 0 ; i <= upbd ; i++)
//     // cout << sum[i] << " ";
    
//     // 2. 遍历s的所有字母 并移动
//     // cout << s.length();
//     for (i = 0; i <= strlen - 1; i++) {
//         sign = s[i] - 'a';
//         times = (sum[i] + sign) % 26;
        
//         s[i] = times + 'a';
//     }
//     cout << s;
// }

// 参考别人的思路：从后往前扫
// 跟我的本质一样，区别是 我将之储存了，而他没有。 我的空间复杂度会变高
int main() {
    vector <int> shifts {3,5,9};
    string s = "abc";

    // def
    int i;
    int length = shifts.size();
    int upbd = length - 1;
    long sum = 0;
    int times = 0;
    // 1. 从后往前
    for (i = upbd; i >= 0; i--) {
        // 1.1 后缀和
        sum += shifts[i];
        s[i] = ((s[i] - 'a') + sum) % 26 + 'a';
    }
    // 2.out 
    cout << s;
}