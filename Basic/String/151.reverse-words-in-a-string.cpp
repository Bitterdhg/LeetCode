// ����һ���ַ��� s �������ת�ַ����е����� ���� ��

// ���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����

// ���㷵��һ����ת s �е���˳���õ����ո��������ַ�����

// �Խ�һ����ָ�� ��old��2 ��new��1��
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
//     s = ' ' + s; // �ֶ���ǰ������һ���ո�
//     int i = 0;
//     int length = s.length();
//     int oldFirst = length - 1;// �ϵĴ���ĵ�һ����ĸ��index
//     int oldLast = length - 1; // �̵Ĵ�������һ����ĸ��index
//     // int newLast = 0; // �µ�string��β�͵�index
//     string newStr;

//     // find blank in old
//     while (oldFirst >= 0) { // ����[]
//         // find blank in old
//         if (s[oldFirst] == ' ') {
//             oldFirst --;
//             oldLast --;
//         } else { //  find letter
//             if (s[oldFirst - 1] == ' ') { //oldFirst �����һ����ĸ��
                
//                 // void ���� ����[]
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


// ���2��ʹ����������
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    string s =  "a good   example";
    //def 
    s = ' ' + s; // �ֶ���ǰ������һ���ո�
    int i = 0;
    int length = s.length();
    int oldFirst = length - 1;// �ϵĴ���ĵ�һ����ĸ��index
    int oldLast = length - 1; // �̵Ĵ�������һ����ĸ��index
    // int newLast = 0; // �µ�string��β�͵�index
    string newStr;

    // find blank in old
    while (oldFirst >= 0) { // ����[]
        // find blank in old
        if (s[oldFirst] == ' ') {
            oldFirst --;
            oldLast --;
        } else { //  find letter
            if (s[oldFirst - 1] == ' ') { //oldFirst �����һ����ĸ��
                
                // void ���� ����[]
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