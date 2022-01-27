# include <iostream>
# include <vector>
using namespace std;
int main() {
    int n = 3;

    // int dp[31];
    vector <int> dp(10); // 注意 vector需要用()
    int i;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    // 1. dp初始化
    dp[0] = 0;
    dp[1] = 1;

    // 2. 递推公式
    for (i = 2; i <= n ; i++) { //i：index 递推公式在初始化之外第一个开始
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}