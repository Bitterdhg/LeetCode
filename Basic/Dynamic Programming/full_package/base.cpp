# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    // "法一 : 先遍历Weight 后遍历物品" 
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
        for (int j = weight[i]; j <= bagWeight; j++) { 
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
        // 展示
        for (int j = 0; j <= bagWeight; j++) {
            cout << dp[j] << " ";
        }
        cout << endl;
    }

    cout << "res : " << dp[bagWeight] << endl;

    cout << "------------------" << endl;
    
    
    
    // 法二: 先遍历物品 后遍历Weight
    // def
    vector<int> dp1(bagWeight + 1, 0);
    // dp1[i] : 指的是 当背包 最大容量 为i 的时候 最大的value，但是他是反复覆盖的.
    // 本质还是二维数组

    // init
    dp1[0] = 0;
    cout << " dp1 array " << endl;
    for (int j = 0; j <= bagWeight; j++) {// 第i件物品
        for (int i = 0; i < weight.size(); i++) { 
            if (j - weight[i] >= 0) {
                dp1[j] = max(dp1[j], dp1[j-weight[i]] + value[i]);
            }
        }
        // 展示
        for (int j = 0; j <= bagWeight; j++) {
            cout << dp1[j] << " ";
        }
        cout << endl;
    }

    cout << "res : " << dp1[bagWeight];

    return 0;

}