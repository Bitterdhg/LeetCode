// ��һ����Сд��ĸ��ɵ��ַ��� S����һ���������� shifts��

// ���ǽ���ĸ���е���һ����ĸ��Ϊԭ��ĸ�� ��λ��������ĸ���ǻ��Ƶģ� 'z'?������?'a'��

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
// �Լ�д�����
// int main() {
//         // ������ ��0����ĸ���ƶ����������԰����������м����� % 26��
//         // ������ i ����ĸ���ƶ������� ��i�ĺ�׺�� % 26 ��
//     vector <int> shifts {3,5,9};
//     string s = "abc";
//     // def
//     int length = shifts.size();
//     int upbd = length - 1;
//     int strlen = s.length();
//     int i;
//     int sign = 0;
//     int times = 0;
//     vector <long> sum(length + 1);
    
//     sum[upbd] = shifts[upbd];
//     // 1. ��׺��
//     for (i = upbd - 1; i >= 0; i--) { // sum[i] ָ��i��i��������ֵĺ�׺��
//         sum[i] = sum[i + 1] + shifts[i];
//     } // sum[] = 17 14 9 
//     // for (i = 0 ; i <= upbd ; i++)
//     // cout << sum[i] << " ";
    
//     // 2. ����s��������ĸ ���ƶ�
//     // cout << s.length();
//     for (i = 0; i <= strlen - 1; i++) {
//         sign = s[i] - 'a';
//         times = (sum[i] + sign) % 26;
        
//         s[i] = times + 'a';
//     }
//     cout << s;
// }

// �ο����˵�˼·���Ӻ���ǰɨ
// ���ҵı���һ���������� �ҽ�֮�����ˣ�����û�С� �ҵĿռ临�ӶȻ���
int main() {
    vector <int> shifts {3,5,9};
    string s = "abc";

    // def
    int i;
    int length = shifts.size();
    int upbd = length - 1;
    long sum = 0;
    int times = 0;
    // 1. �Ӻ���ǰ
    for (i = upbd; i >= 0; i--) {
        // 1.1 ��׺��
        sum += shifts[i];
        s[i] = ((s[i] - 'a') + sum) % 26 + 'a';
    }
    // 2.out 
    cout << s;
}