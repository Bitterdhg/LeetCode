// 实现 strStr() 函数。

// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
// 如果不存在，则返回  -1 。
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string haystack = "aaaaa";
    string needles = "a";

    //def
    int lenH = haystack.length();
    int lenN = needles.length();
    int i = 0;
    int j = 0; // haystack
    int result = -1;

    // needles = NULL
    if (needles == "") cout << 0;
    else {
        // find 1st letter of needles
        j = -1;
        while (j <= lenH - 1 && haystack[++j] != needles[0]);
            // j stop 在第一个相同的letter
        if (j == lenH) {
            cout << -1;
            return 0;
        } else { 
            result = j;
            // j--;
            i = 0;
            // find left letter of needles
            // j haystack
            while (haystack[++j] == needles[++i] && j <= lenH - 1);
            if (i == lenN) cout << result;
            else cout << -1;
        } //if (j == lenH)
    }

    return 0;
}