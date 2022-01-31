// 自解法一： 迭代
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// int main() {
//     // def
//     char temp;
//     int i;
//     string s = "hello";
//     int length = s.length();
//     int upbd;
//     upbd = (length % 2 == 0) ? (length / 2 - 1) : ((length - 1) / 2 - 1);
//     for (i = 0; i <= upbd; i++) {
//         temp = s[i];
//         s[i] = s[length - 1 - i];
//         s[length - 1 - i] = temp;
//     }
//     cout << s;
//     return 0;
// }

// 自解法二：双指针
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// int main() {
//     string s = "ab cd";
//    // def
//     char temp;
//     int i;
//     int length = s.length();
//     int left = 0;
//     int right = length - 1;
//     char tmp;

//     while (left <= right) {
//         tmp = s[left];
//         s[left] = s[right];
//         s[right] = tmp;
//         left++;
//         right--;
//     }
//         cout << s;
    
//     return 0;
// }