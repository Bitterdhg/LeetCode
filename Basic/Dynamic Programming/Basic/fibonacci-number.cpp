# include <iostream>
# include <vector>
using namespace std;
int main() {
    int n = 3;

    // int dp[31];
    vector <int> dp(10); // ע�� vector��Ҫ��()
    int i;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    // 1. dp��ʼ��
    dp[0] = 0;
    dp[1] = 1;

    // 2. ���ƹ�ʽ
    for (i = 2; i <= n ; i++) { //i��index ���ƹ�ʽ�ڳ�ʼ��֮���һ����ʼ
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}