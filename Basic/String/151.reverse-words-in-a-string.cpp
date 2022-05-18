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
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;

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

// 5.18 重开系列
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void reverseStr(string &s, int start, int end) {
    // input : 
    //      start : start_index
    //      end :   end_index 
    // 区间: [ )
    for (int i = 0; i < (end - start)/2; i++){
        swap(s[start + i], s[(end-1) - i]);
    }
}

string eraseBlank(string &s) {
    // double point
    // 2 cases : swap or slowpoint ++
    // fastpoint must be ++

    int slowPoint = 0;
    int fastPoint = 0;
    int begin = 0;
    // begin
    while (s[slowPoint] == ' ') {
        slowPoint++;
    }
    begin = slowPoint;
    // middle
    fastPoint = slowPoint;
    while(fastPoint < s.length()) {
        if (s[fastPoint] == ' ' && s[fastPoint-1] == ' ') {
            fastPoint++;
        } else {
            s[slowPoint] = s[fastPoint];
            fastPoint++;
            slowPoint++;
        }
    }
    // end
    slowPoint--; // slowPoint在外面
    while (s[slowPoint] == ' ') {
        slowPoint --;
    }
    return s.substr(begin, slowPoint - begin + 1);
}

void reverseWord(string &s) {
    int len = s.length();
    int begin = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            reverseStr(s, begin, i);
            begin = i + 1;
        }
    }
    reverseStr(s, begin, len);
    // reverseStr(s.substr(begin, len - begin));
}

string reverseWords(string s) {
    
    reverseStr(s, 0, s.length());
    s = eraseBlank(s);
    reverseWord(s);
    return s;
    }
 


int main(){
    // string s = " the  sky  is  blue ";
    // string s = "  hello world  ";
    string s = "a good   example";
    string res = "";
    res = reverseWords(s);
    cout << res<<"|";
    return 0;
}