// ��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

// ����������?����Ϊ��

// ����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
// Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
// ���������� ���Ϊ?1����ô��������ǿ�������
// ��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��

// ��һ�����
// ˼·��
# include <iostream>
# include <vector>
# include <cmath>
# include <unordered_set>
using namespace std;

int Sum(int n) {
    int sum = 0;
    while ( 0 < n) {
        sum += (n % 10) * (n % 10);
        n = n / 10;
    }
    return sum;
}

int main (){
    int n = 2;
    // def
    unordered_set <int> set;

    // iter
    while (true) {
        n = Sum(n);
        // 1 
        if (n == 1) {
            cout << "true";
            return 0;
        } else {
            // found
            if (set.find(n) != set.end()) {
                cout << "false";
                return 0;
            // not found
            }  else {
                set.insert(n);
            } // if (set.find(n) != set.end())
        } //if (n == 1)
    }

    return 0;
}