
// ������������¥�ݡ���Ҫ n ������ܵ���¥����

// ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

# include <iostream>
# include <vector>
using namespace std;
int main() {
    //def
    int n = 4;
    vector <int> dp(46); 
    int i;
    // 1. initial
    dp[1] = 1;
    dp[2] = 2;
    // 2. formulate
    for (i = 3; i <= n ; i++) { //i�� ��i������
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}