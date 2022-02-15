// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

// 法一：自解
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

int hashFunc (char x) {
    int num = int(x - 'a');
    return num;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    // def
    int coutS[26] = {};
    int coutT[26] = {};
    for (int i = 0; i <= 25; i++) {
        coutS[i] = 0;
        coutT[i] = 0;
    }

    int lenS = s.length();
    int lenT = t.length();

    // cout 
    // 1. cout S
    for (int i = 0; i < lenS; i++) {
        coutS[hashFunc(s[i])]++;
    }
    // 2. cout T
    for (int i = 0; i < lenT; i++) {
        coutT[hashFunc(t[i])]++;
    }
    
    // out
    for (int i = 0; i <= 25; i++) {
        if (coutS[i] != coutT[i]) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}