# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    
    // 1. def
    vector<vector<int>> dp(weight.size(), vector<int> (bagWeight + 1, 0));
    // dp[i][j]
    // i 为横坐标 代表 第i个物品
    // j 为纵坐标 代表bag的最大容量
    // dp[i][j] 代表考虑第i个物品时候 在bag最大容量是j的时候 最大value

    // 2. init
    // 第一行
    for (int j = weight[0] ;j <= bagWeight; j++) {
        //  注意 j 从weight[0]开始的
        dp[0][j] = value[0];
    } 
    // 第一列
    // 应该全是0 因为在最大容量全是0的时候 所有物品都放不进去 所以value 都是0

    // 3. formulate
    for (int i = 1; i < value.size(); i++) { // i是物品
        for(int j = 1; j <= bagWeight; j++) { // j是bag的最大容量
            // 不选择当前这个物品 i
            // 理解：代码表现出来的是 : j - weight[i] < 0 就会越界!!!
            if (j < weight[i]) {
                dp[i][j] = dp[i-1][j];
            // 选择当前这个物品
            // 理解：最大容量的背包 理论上能装这个物品，所以需要遍历确定哪个是最大的
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
            }
        }
    }

    for (int i = 0; i < value.size(); i++) {
        for (int j = 0; j <= bagWeight; j++) {
            cout << dp[i][j] << " "; 
        }
        cout << endl;
    }
    
}