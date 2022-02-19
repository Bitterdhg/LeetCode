// 给你两个字符串：A 和 B ，判断 A 能不能由 B 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// B 中的每个字符只能在 A 中使用一次。

// 法一：数组
// 建立hash数组形式
// 遍历A，然后再B中找，即erase，若返回0，则out false 反之 out true
# include <iostream>
using namespace std;
int main() {
    string A = "a";
    string B = "b";

    // def
    int hash[26] = {};

    // 1. hash array 
    for (char b : B) {
        hash[b - 'a'] ++;
    }
    // for (int i = 0; i < 26 ;i++) {
    //     cout << hash[i] <<" ";
    // }

    // 2. 遍历A，然后在array中找
    for (char a : A) {
        // 若数量 > 0 ,则碰到数量--，
        if (hash[a - 'a'] > 0) {
            hash[a - 'a'] --;
        // 数量 <= 0 ,则out false 
        } else {
            cout << "false";
            return 0;
        }
    }
    // 全遍历完A  out true
    cout << "true";

    return 0;
}

