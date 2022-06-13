# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
vector<vector<int>> res;
vector<int> path;

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }

public:
    void backtracking(int n, int k, int startIndex) {
        // stop
        if (path.size() == k) {
            res.push_back(path); // 存放结果;
            return;
        }
        // recursion one-layer
        else {
            // for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）)
            for (int i = startIndex; i <= n; i++) {  // 控制树的横向遍历
                path.push_back(i); // (当前这层) 处理节点 
                backtracking(n, k, i+1); // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
                path.pop_back(); // 回溯，撤销处理的节点
            }
        }
    }
};

int main() {
    Solution solution = Solution();
    int n = 4;
    int k = 2;
    vector<vector<int>> res = solution.combine(n, k);
    for (int i = 0; i < res.size(); i++) {
         for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
         }
         cout << endl;
    }
}