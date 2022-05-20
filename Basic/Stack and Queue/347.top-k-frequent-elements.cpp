// 给你一个整数数组 nums 和一个整数 k ，
// 请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
# include <iostream>
# include <stack>         
# include <vector>     
# include <deque>       
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    }
};

int main () {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution solution;
    for (int i = 0; i < solution.topKFrequent(nums, k).size(); i++) {
        cout << solution.topKFrequent(nums, k)[i] << " ";
    }
    return 0;
}
