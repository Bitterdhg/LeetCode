# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // def
    vector<int> dp(bagWeight + 1, 0);
    // dp[i] : 指的是 当背包 最大容量 为i 的时候 最大的value，但是他是反复覆盖的.
    // 本质还是二维数组

    // init
    dp[0] = 0;

    cout << " dp array " << endl;
    for (int i = 0; i < weight.size(); i++) {// 第i件物品
        
        for (int j = bagWeight; j >= weight[i]; j--) { 
            //  j >= weight[i]数组理解：就是之前的就是上一次循环直接落下来的 不用改变
            // 直接理解就是二维数组 if (j < weight[i]) dp[i][j] = dp[i-1][j]; 不用改变
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
        // 展示
        for (int j = 0; j <= bagWeight; j++) {
            cout << dp[j] << " ";
        }
        cout << endl;
    }


    cout << "res : " << dp[bagWeight];
    return 0;


}