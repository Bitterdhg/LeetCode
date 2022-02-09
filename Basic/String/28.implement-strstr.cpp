// ʵ��?strStr()?������

// ���������ַ���?haystack �� needle �������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�ã��±�� 0 ��ʼ����
// ��������ڣ��򷵻�? -1 ��

// �Խ�һ��ģ��
// ʱ�临�Ӷȣ�O(n*m) n:haystack.length() m: needle.length()
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
//             while (j <= lenH - 1 && haystack[++j] != needle[0]); // �������ж� �����overstack!!!
//                 // j stop �ڵ�һ����ͬ��letter
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

// ������Brute-Force�㷨 ����׼������
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
//     bool flag = true; // false: ��match true��match
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

// �Խ����KMP�㷨
// �������ƣ��������-1
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// �������ƣ��������-1
void getNext(int * next, string & s) {
    int prefix = -1; // -1 important 
    int suffix = 1;
    int len = s.length();

    next[0] = -1; 
    for (suffix = 1; suffix <= len - 1; suffix++) { 

        // ����һ��������������ʱ�򣬼�һ�� prefix >= 0��Ȼ���-1��ʼ

        // 1. ȥ�ҵ� ����ǰ��׺
        while (prefix >= 0 && s[prefix + 1] != s[suffix]) { // + 1   important
            prefix = next[prefix];
        }
        // 2. ������ͣ������λ�õ�Ԫ�� ��� �� ��ֱ֮�Ӹ�ֵΪ-1
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
    // 1. Next����
        getNext(next, needle);
        // for (int i = 0; i <= 2; i++) {
        //     cout << next[i] <<" ";
        // }

    // 2. match
        // string haystack = "hello";
        // string needle = "ll";

        for (hI = 0; hI <= lenH - 1; hI++) {
            // 1. find ����ǰ��׺
            while (nI >= 0 && haystack[hI] != needle[nI + 1]) { // ��ƥ��
                nI = next[nI];
            }
            // 2. same
            if (haystack[hI] == needle[nI + 1] ) {  // ƥ�䣬needI��hayIͬʱ����ƶ�
                nI++; // �Ƚ���һ��λ�� nI++ ����hI��Ϊ ���Զ������
            }

            // 3�� �Ƿ�out
            if ((nI + 1) == lenN) {
                cout << hI - lenN + 1;
                return 0;
            }
        }
        cout << -1;
    }
    
    return 0;
}

// �ܽ᣺
//https://www.notion.so/KMP-28-strStr-24e15c169e61420989d7ad2d009add91#4a9b60aba59c4e4e8421cf7f91a48170