// ʵ��?strStr()?������

// ���������ַ���?haystack �� needle �������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�ã��±�� 0 ��ʼ����
// ��������ڣ��򷵻�? -1 ��

//Todo ��û��д��ڶ���ѭ�� ����һ������ĸƥ����治ƥ�� ��Ҫ����search
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    string haystack = "aa";
    string needle = "aa";

    //def
    int lenH = haystack.length();
    int lenN = needle.length();
    int i = 0;
    int j = 0; // haystack
    int result = -1;

    // needle = NULL
    if (needle == "") cout << 0;
    else {
        // find 1st letter of needle
        j = -1;
        while (j <= lenH - 1 && haystack[++j] != needle[0]);
            // j stop �ڵ�һ����ͬ��letter
        if (j == lenH) {
            cout << -1;
            return 0;
        } else { 
            result = j;
            // j--;
            i = 0;
            // find left letter of needle
            // j haystack
            while (haystack[++j] == needle[++i] && j <= lenH - 1);
            if (i == lenN) cout << result;
            else cout << -1;
        } //if (j == lenH)
    }

    return 0;
}