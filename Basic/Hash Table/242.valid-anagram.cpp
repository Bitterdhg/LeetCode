// ���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
// ע�⣺�� s �� t ��ÿ���ַ����ֵĴ�������ͬ����� s �� t ��Ϊ��ĸ��λ�ʡ�

// ��һ���Խ⣺����
// # include <iostream>
// # include <vector>
// # include <cmath>
// using namespace std;

// int hashFunc (char x) {
//     int num = int(x - 'a');
//     return num;
// }

// int main() {
//     string s = "anagram";
//     string t = "nagaram";

//     // def
//     int coutS[26] = {};
//     int coutT[26] = {};
//     for (int i = 0; i <= 25; i++) {
//         coutS[i] = 0;
//         coutT[i] = 0;
//     }

//     int lenS = s.length();
//     int lenT = t.length();

//     // cout 
//     // 1. cout S
//     for (int i = 0; i < lenS; i++) {
//         coutS[hashFunc(s[i])]++;
//     }
//     // 2. cout T
//     for (int i = 0; i < lenT; i++) {
//         coutT[hashFunc(t[i])]++;
//     }
    
//     // out
//     for (int i = 0; i <= 25; i++) {
//         if (coutS[i] != coutT[i]) {
//             cout << "false";
//             return 0;
//         }
//     }
//     cout << "true";
//     return 0;
// }

// ��⣺����
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

int main() {
    string s = "anagram";
    string t = "nagaram";

    // def
    int record[26] = {};
    int lenS = s.length();
    int lenT = t.length();

    for (int i = 0; i < lenS; i++) {
        record[s[i] - 'a'] ++;
    }  

    for (int i = 0; i < lenT; i++) {
        record[t[i] - 'a'] --;
    }

    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}
