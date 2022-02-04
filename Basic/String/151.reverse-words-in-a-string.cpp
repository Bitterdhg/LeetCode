// 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

// 请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

// 自解一：三指针 （old）2 （new）1个
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

// void copy2new(string &newStr, string oldStr, int oldStart, int oldLast) {
//     int i = oldStart;
//     while (i <= oldLast) {
//         newStr += oldStr[i];
//         i ++;
//     }
//     newStr += " ";
// }

// int main() {
//     string s =  "a good   example";
//     //def 
//     s = ' ' + s; // 手动在前面增加一个空格
//     int i = 0;
//     int length = s.length();
//     int oldFirst = length - 1;// 老的词语的第一个字母的index
//     int oldLast = length - 1; // 捞的词语的最后一个字母的index
//     // int newLast = 0; // 新的string的尾巴的index
//     string newStr;

//     // find blank in old
//     while (oldFirst >= 0) { // 区间[]
//         // find blank in old
//         if (s[oldFirst] == ' ') {
//             oldFirst --;
//             oldLast --;
//         } else { //  find letter
//             if (s[oldFirst - 1] == ' ') { //oldFirst 到最后一个字母了
                
//                 // void 复制 区间[]
//                 // void copy2new(string &newstr, string oldstr, int oldStart, int oldLast) 
//                 copy2new (newStr, s, oldFirst, oldLast);
                
//                 oldFirst = oldFirst - 1;
//                 oldLast  = oldFirst;
//             } else {
//                 oldFirst --;
//             }   //if (s[oldFirst - 1] == ' ') 
//         }// if (s[oldFirst] == " ")
//     }
    
//     // out
//     newStr.pop_back();
//     cout << newStr.length()<< endl;
//     cout << newStr;
//     return 0;
// }


// 题解2：使用语言特性
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    string s =  "a good   example";
    //def 
    s = ' ' + s; // 手动在前面增加一个空格
    int i = 0;
    int length = s.length();
    int oldFirst = length - 1;// 老的词语的第一个字母的index
    int oldLast = length - 1; // 捞的词语的最后一个字母的index
    // int newLast = 0; // 新的string的尾巴的index
    string newStr;

    // find blank in old
    while (oldFirst >= 0) { // 区间[]
        // find blank in old
        if (s[oldFirst] == ' ') {
            oldFirst --;
            oldLast --;
        } else { //  find letter
            if (s[oldFirst - 1] == ' ') { //oldFirst 到最后一个字母了
                
                // void 复制 区间[]
                // void copy2new(string &newstr, string oldstr, int oldStart, int oldLast) 
                copy2new (newStr, s, oldFirst, oldLast);
                
                oldFirst = oldFirst - 1;
                oldLast  = oldFirst;
            } else {
                oldFirst --;
            }   //if (s[oldFirst - 1] == ' ') 
        }// if (s[oldFirst] == " ")
    }
    
    // out
    newStr.pop_back();
    cout << newStr.length()<< endl;
    cout << newStr;
    return 0;
}