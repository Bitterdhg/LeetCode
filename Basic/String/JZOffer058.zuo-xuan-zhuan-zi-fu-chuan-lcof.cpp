// �ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
// ���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��

// ����: s = "abcdefg", k = 2
// ���: "cdefgab"

// �Խ�һ����string
// too simple

// �Խ����resize
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;



int main() {
    string s = "lrloseumgh";
    int k = 6;

    //def
    int len = s.length();
    int left = 0;
    int right = len - 1;

    //1. �Ƚ�ǰ��ĸ��ں���
    s.resize(len * 2);
    for (left = 0; left <= k - 1; left++) {
        s[++right] = s[left];
    }
    // cout << s;

    // 2. ǰ��
    right = k - 1;
    for (left = 0; left <= len - 1; left++) {
        s[left] = s[++right];
    }
    s.resize(len);
    cout << s;

    return 0;
}