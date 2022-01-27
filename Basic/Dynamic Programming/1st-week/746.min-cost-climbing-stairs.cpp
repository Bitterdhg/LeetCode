// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

// 请你计算并返回达到楼梯顶部的最低花费。
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    // def
    vector <int> cost {1,100,1,1,1,100,1,1,100,1}; 
    vector <int> dp(cost.size(), 0);
    int i;
    int choose = -1;
    int upbd = cost.size() - 1;
    // 1. 意义
    // dp[i] ：i层楼梯的最小cost 
    // 2. initial
    dp[0] = cost[0];
    dp[1] = cost[1]; // 因为dp[1] < dp[0] + dp[1]
    // 3. formulate
    for (i = 2; i <= upbd ; i++) {
        choose = (dp[i - 1] > dp[i - 2]) ? (i-2) : (i-1);
        dp[i] = dp[choose] + cost[i];
    }
    cout << min(dp[upbd], dp[upbd - 1]);
    return 0;
}