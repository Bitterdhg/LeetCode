// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
void reverse (string& s, int start, int end) { // 区间[]
    char temp;
    int i;
    int length = end - start + 1;
    int upbd;
    upbd = (length % 2 == 0) ? (length / 2 - 1) : ((length - 1) / 2 - 1);
    for (i = start; i <= start + upbd; i++) {
        temp = s[i];
        s[i] = s[end - (i - start)];
        s[end - (i - start)] = temp;
    }
}

int main() {
    string s = "abcd";
    int k = 2;
    // def
    int length = s.length();
    int left = length; // 剩余的数量
    int upbd = length - 1;
    // reverse(s, 0, 3); // 引用传递
    // cout << s;
    while (left >= 1) {  
        if (left < k) { //剩余字符全部反转。
            reverse (s, upbd - left + 1,upbd); // 区间[]
            break;
        } else {
            reverse (s, upbd - left + 1,upbd - left + k); // 区间[]
            left -= 2 * k;
        } // if ((length - j) < k)
    }
        
    cout << s;
    return 0;
}