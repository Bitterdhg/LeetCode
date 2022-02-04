// 实现?strStr()?函数。

// 给你两个字符串?haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
// 如果不存在，则返回? -1 。

//Todo 还没有写完第二个循环 就是一来首字母匹配后面不匹配 需要继续search
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string haystack = "aa";
    string needle = "aa";

    //def
    int lenH = haystack.length();
    int lenN = needle.length();
    int i = 0;
    int j = 0; // haystack
    int result = -1;

    // needle = NULL
    if (needle == "") cout << 0;
    else {
        // find 1st letter of needle
        j = -1;
        while (j <= lenH - 1 && haystack[++j] != needle[0]);
            // j stop 在第一个相同的letter
        if (j == lenH) {
            cout << -1;
            return 0;
        } else { 
            result = j;
            // j--;
            i = 0;
            // find left letter of needle
            // j haystack
            while (haystack[++j] == needle[++i] && j <= lenH - 1);
            if (i == lenN) cout << result;
            else cout << -1;
        } //if (j == lenH)
    }

    return 0;
}