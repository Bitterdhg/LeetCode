// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」?定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为?1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

// 法一：题解
// 思路：
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