// ��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
// ���룺s = "We are happy."
// �����"We%20are%20happy."

// �Խ�һ�������µ�string
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string s = "We are happy.";

    // def
    string str;
    int length = s.length();
    int i = 0;
    int j = -1; // ָ��ǰnew str��β�͵�index
    // find     
    while (i <= length - 1) {
        if (s[i] == ' ') {
            str += "%20";
            i ++;
        } else {
            str += s[i];
            i++;
        } // if (s[i] == ' ')
    }
    cout << str;
    return 0;
}

