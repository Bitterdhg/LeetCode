// ����һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�

// �����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�

// ������㲢���شﵽ¥�ݶ�������ͻ��ѡ�
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
        // ������ ��0����ĸ���ƶ����������԰����������м����� % 26��
        // ������ i ����ĸ���ƶ������� ��i�ĺ�׺�� % 26 ��
    vector <int> shifts {3,5,9};
    string s = "abc";
    // def
    int length = shifts.size();
    int upbd = length - 1;
    int strlen = s.length();
    int i;
    int sign = 0;
    int times = 0;
    vector <long> sum(length + 1);
    
    sum[upbd] = shifts[upbd];
    // 1. ��׺��
    for (i = upbd - 1; i >= 0; i--) { // sum[i] ָ��i��i��������ֵĺ�׺��
        sum[i] = sum[i + 1] + shifts[i];
    } // sum[] = 17 14 9 
    // for (i = 0 ; i <= upbd ; i++)
    // cout << sum[i] << " ";
    
    // 2. ����s��������ĸ ���ƶ�
    // cout << s.length();
    for (i = 0; i <= strlen - 1; i++) {
        sign = s[i] - 'a';
        times = (sum[i] + sign) % 26;
        
        s[i] = times + 'a';
    }
    cout << s;
}