// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。


# include <iostream>
# include <stack>         
# include <vector>     
# include <deque>       
using namespace std;
class Solution {
    class MyQueue {
    public:
        /** 单调队列 **/
        deque<int> que;

        /** 无参初始化 **/
        MyQueue() {

        } 

        /** push **/
        void push(int value) {
            // que.empty() != true 必须放前面，否则 que 是空的时候，没办法比较，就会报错
            while ((que.empty() != true) && (que.back() < value)) {
                que.pop_back();
            }
            que.push_back(value);
        }

        /** pop **/
        void pop(int value) {
            if (value == que.front()) {
                que.pop_front();
            }
        }

        int front() {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
         MyQueue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};

int main () {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    for (int i = 0; i < solution.maxSlidingWindow(nums, k).size(); i++) {
        cout << solution.maxSlidingWindow(nums, k)[i] << " ";
    }
    return 0;
}