// ���������ַ�����A �� B ���ж� A �ܲ����� B ������ַ����ɡ�

// ������ԣ����� true �����򷵻� false ��

// B �е�ÿ���ַ�ֻ���� A ��ʹ��һ�Ρ�

// ��һ������
// ����hash������ʽ
// ����A��Ȼ����B���ң���erase��������0����out false ��֮ out true
# include <iostream>
using namespace std;
int main() {
    string A = "a";
    string B = "b";

    // def
    int hash[26] = {};

    // 1. hash array 
    for (char b : B) {
        hash[b - 'a'] ++;
    }
    // for (int i = 0; i < 26 ;i++) {
    //     cout << hash[i] <<" ";
    // }

    // 2. ����A��Ȼ����array����
    for (char a : A) {
        // ������ > 0 ,����������--��
        if (hash[a - 'a'] > 0) {
            hash[a - 'a'] --;
        // ���� <= 0 ,��out false 
        } else {
            cout << "false";
            return 0;
        }
    }
    // ȫ������A  out true
    cout << "true";

    return 0;
}

