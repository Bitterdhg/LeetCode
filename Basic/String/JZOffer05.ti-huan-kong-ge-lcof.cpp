// ��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
// ���룺s = "We are happy."
// �����"We%20are%20happy."

// �Խ�һ�������µ�string
// ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ�O��n��

// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// int main() {
//     string s = "We are happy.";

//     // def
//     string str;
//     int length = s.length();
//     int i = 0;
//     int j = -1; // ָ��ǰnew str��β�͵�index
//     // find     
//     while (i <= length - 1) {
//         if (s[i] == ' ') {
//             str += "%20";
//             i ++;
//         } else {
//             str += s[i];
//             i++;
//         } // if (s[i] == ' ')
//     }
//     cout << str;
//     return 0;
// }


// ���������˼·��������˫ָ��
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string s = "We are happy.";

    // def
    int length = s.length();
    int leftPointer = length - 1; // ��ǰ������Ԫ��
    int rightPointer = 3 * length - 1; // ��ǰ��������Ԫ��Ӧ�÷ŵ�λ�õĵ�����
    int i;

    // ������
    s.resize(3 * length);
    for (; leftPointer >= 0; leftPointer--) {// ��ָ�뵽��Tail ����
         if (s[leftPointer] == ' ') {
             s[rightPointer--] = '0';
             s[rightPointer--] = '2';
             s[rightPointer--] = '%';
         } else {
            s[rightPointer--] = s[leftPointer];
         } // if (s[leftPointer] == ' ') 
    }

    for (i = rightPointer + 1; i <= 3 * length - 1; i++) {
        cout << s[i];
    }
    
    return 0;
}

