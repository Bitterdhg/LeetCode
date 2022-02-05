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
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string haystack = "mississippia";
    string needle = "issip";
    
    //def
    int lenH = haystack.length();
    int lenN = needle.length();
    int hI = 0;// haystack 's first index
    int nI = 0;// needle 's index
    bool flag = true; // false: ��match true��match
    // match
    if (needle == "") {
        cout << 0;
        return 0;
    } else {
        for (hI = 0; hI <= lenH - lenN; hI++) {
            flag = true;
            for (nI = 0; nI <= lenN - 1; nI++) {
                if (haystack[hI + nI] != needle[nI]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << hI;
                return 0;
            }
        }
        cout << -1;
    }
    
    return 0;
}