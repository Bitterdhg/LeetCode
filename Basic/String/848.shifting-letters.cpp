// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

// 请你计算并返回达到楼梯顶部的最低花费。
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
        // 分析： 第0个字母右移动次数（后迷案的数字所有加起来 % 26）
        // 即：第 i 个字母右移动次数是 （i的后缀和 % 26 ）
    vector <int> shifts {3,5,9};
    string s = "abc";
    // def
    int length = shifts.size();
    int upbd = length - 1;
    int strlen = s.length();
    int i;
    int sign = 0;
    int times = 0;
    vector <long> sum(length + 1);
    
    sum[upbd] = shifts[upbd];
    // 1. 后缀和
    for (i = upbd - 1; i >= 0; i--) { // sum[i] 指第i即i后面的数字的后缀和
        sum[i] = sum[i + 1] + shifts[i];
    } // sum[] = 17 14 9 
    // for (i = 0 ; i <= upbd ; i++)
    // cout << sum[i] << " ";
    
    // 2. 遍历s的所有字母 并移动
    // cout << s.length();
    for (i = 0; i <= strlen - 1; i++) {
        sign = s[i] - 'a';
        times = (sum[i] + sign) % 26;
        
        s[i] = times + 'a';
    }
    cout << s;
}