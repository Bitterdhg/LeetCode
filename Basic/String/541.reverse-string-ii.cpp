// ���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
// ���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
// �Խⷨһ������
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// void reverse (string& s, int start, int end) { // ����[]
//     char temp;
//     int i;
//     int length = end - start + 1;
//     int upbd;
//     upbd = (length % 2 == 0) ? (length / 2 - 1) : ((length - 1) / 2 - 1);
//     for (i = start; i <= start + upbd; i++) {
//         temp = s[i];
//         s[i] = s[end - (i - start)];
//         s[end - (i - start)] = temp;
//     }
// }

// int main() {
//     string s = "abcd";
//     int k = 2;
//     // def
//     int length = s.length();
//     int left = length; // ʣ�������
//     int upbd = length - 1;
//     // reverse(s, 0, 3); // ���ô���
//     // cout << s;
//     while (left >= 1) {  
//         if (left < k) { //ʣ���ַ�ȫ����ת��
//             reverse (s, upbd - left + 1,upbd); // ����[]
//             break;
//         } else {
//             reverse (s, upbd - left + 1,upbd - left + k); // ����[]
//             left -= 2 * k;
//         } // if ((length - j) < k)
//     }
        
//     cout << s;
//     return 0;
// }

// �Խⷨ����˫ָ��
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// void reverse (string& s, int start, int end) { // ����[]
//     char temp;
//     while (start <= end) {
//         temp = s[start];
//         s[start] = s[end];
//         s[end] = temp; 

//         start ++;
//         end --;
//     }
// }

// int main() {
//     string s = "abcdefg";
//     int k = 2;
//     // def
//     int length = s.length();
//     int left = length; // ʣ�������
//     int upbd = length - 1;
//     // reverse(s, 0, 3); // ���ô���
//     // cout << s;
//     while (left >= 1) {  
//         if (left < k) { //ʣ���ַ�ȫ����ת��
//             reverse (s, upbd - left + 1,upbd); // ����[]
//             break;
//         } else {
//             reverse (s, upbd - left + 1,upbd - left + k); // ����[]
//             left -= 2 * k;
//         } // if ((length - j) < k)
//     }
        
//     cout << s;
//     return 0;
// }

// �ο���⣺ģ�� + �⺯��
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    string s = "abcd";
    int k = 2;

    // def
    int length = s.length();
    int upbd = length - 1;
    int i = 0; // ��Ҫ��ת����index
    // reverse

    // ���� k �� -> ʣ���ַ�ȫ����ת ;
    // С�� 2k �����ڻ���� k ��,��תǰ k ���ַ��������ַ�����ԭ����
    while ( i <= upbd ) { // ʣ������ length - i
        if (length - i < k) { // ���� k ��  ʣ���ַ�ȫ����ת
            reverse(s.begin() + i, s.end());
        } else { // С�� 2k �����ڻ���� k ��
            reverse(s.begin() + i, s.begin() + i + k);// ����:[) ;
        } //if (length - i)
        i += 2 * k;
    }

    // out 
    cout << s;
    return 0;
}