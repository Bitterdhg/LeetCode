
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

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
    for (i = 3; i <= n ; i++) { //i： 第i个阶梯
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}