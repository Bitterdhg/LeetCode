//长度最小的 连续子数组 
//如果不存在符合条件的子数组，返回 0 。
# include <iostream>
# include <vector>
using namespace std;
// Approach 1 : 暴力法
// int main() {
        //def
        // vector<int> nums = {1,1,1,1,1,1,1,1};
        // int target = 11;
        // int length = nums.size();

//         int result = INT32_MAX; // 最终的结果
//         int sum = 0; // 子序列的数值之和
//         int subLength = 0; // 子序列的长度
//         for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
//             sum = 0;
//             for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
//                 sum += nums[j];
//                 if (sum >= target) { // 一旦发现子序列和超过了target，更新result
//                     subLength = j - i + 1; // 取子序列的长度
//                     result = result < subLength ? result : subLength;
//                     break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
//                 }
//             }
//         }
//         // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
//         result = (result == INT32_MAX) ? 0 : result;
//         cout << result;
//         return 0;
// }

// Approach 2 : 双指针（队列的形式）
// int main() {
//     vector<int> nums = {2,3,1,2,4,3};
//     int target = 7;
//     int length = nums.size();

//     int result = INT32_MAX;
//     int sum = 0; // 滑动窗口数值之和
//     int i = 0; // 滑动窗口起始位置
//     int subLength = 0; // 滑动窗口的长度
//     for (int j = 0; j < nums.size(); j++) {
//         sum += nums[j]; // j表示当前子序列的结束位置
//         // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
//         while (sum >= target) {
//             subLength = (j - i + 1); // 取子序列的长度
//             result = (result < subLength) ? result : subLength;
//             sum -= nums[i]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
//             i++;
//         }
//     }
//     // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
//     result = (result == INT32_MAX) ? 0 : result;
//     cout << result;
//     return 0;
// } 

// 自己写的 双指针
// int main() {
    // // def
    // vector<int> nums = {2,3,1,2,4,3};
    // int target = 7;
    //     int length = nums.size();
    //     int upBd = length - 1;
    //     int sum = 0;
    //     int subLength = INT32_MAX;

    //     int sIdx = 0;
    //     int eIdx = 0;
    //     // 1. search
    //     // 1.1 首确定 尾增加（sIdx不变 ，eIdx增加）
    //     for (eIdx = 0; eIdx <= upBd ;eIdx++) { // eIdx : 当前subarray 的尾下标
    //         sum += nums[eIdx];
    //         // 1.1.1满足target //首增加 尾固定（sIdx增加 ，eIdx不变）
    //         while (sum >= target) { 
    //             // 1.1.1.1 judege 是否update sublenth
    //             if ((eIdx - sIdx + 1) < subLength) {
    //                 subLength = eIdx - sIdx + 1;
    //             }
    //             // 1.1.1.2 一定出入队列
    //             sum -= nums[sIdx];
    //             sIdx++;
    //         }
    //     }
    //     // 2. out 
    //     if (subLength == INT32_MAX) cout << 0;
    //     else cout << subLength;

    //     cout << endl;
    //     cout << nums.begin();
    //     return 0;

//Approach 3:前缀和 + 二分查找
// 时间复杂度：总时间复杂度是O(nlogn)
// int main() {
//         vector<int> nums = {2,3,1,2,4,3};
//         int s = 7;
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         int ans = INT_MAX;
//         vector<int> sums(n + 1, 0); 
//         // 为了方便计算，令 size = n + 1 
//         // sums[0] = 0 意味着前 0 个元素的前缀和为 0
//         // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
//         // 以此类推
//         for (int i = 1; i <= n; i++) {
//             sums[i] = sums[i - 1] + nums[i - 1];
//         }

//         for (int i = 1; i <= n; i++) {
//             int target = s + sums[i - 1];
//             auto bound = lower_bound(sums.begin(), sums.end(), target);
//             if (bound != sums.end()) {
//                 ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
//             }
//         }
//         ans = (ans == INT_MAX) ? 0 : ans;
//         cout << ans; 
// }

// 手写一个 前缀和 + 二分查找
// 还未写完！！Todo


// int lowerBound (int [] nums ,int [] sum, int sIdx, int target, int lftIdx,int ritIdx) {
//     int midIdx;
//     while (lftIdx <= ritIdx) { // 区间是[] 
//         midIdx = (lftIdx + ritIdx) / 2;
//         if (sum[midIdx] - sum[sIdx] >= target) { // left 
//             ritIdx = midIdx - 1; 
//         } else { //right
//             lftIdx = midIdx + 1;
//         } //if (sum[midIdx] >= target)
//     }
//     return midIdx;
// }

// int main() {
//     vector<int> nums = {2,3,1,2,4,3};
//     int target = 7;
//     // def
//     int length = nums.size();
//     int i;
//     int upbd = length - 1; 
//     int sum[100000 + 1];
//     // 1. 前缀和
//     sum[0] = 0;
//     for (i = 1; i <= upbd + 1; i++) { // sum[1]表示前1个前缀和
//         sum[i] += (sum[i - 1] + nums[i - 1]);
//     }
//     //for (i = 0 ; i <= upbd + 1 ;i++) cout<< sum[i] << " ";
//     // 2. binary search
//     int lftIdx = 0;
//     int ritIdx = upbd;
//     int midIdx;
//     int sIdx = 0;
//     int result = 0;
//     int Idx = 0;
//     for (sIdx = 0 ;sIdx <= upbd ;sIdx++) { // sIdx 是队首
//         // binary search
//         // int lowerBound (int [] nums ,int [] sum, int sIdx, int target, int lftIdx,int ritIdx) 
//         Idx = lowerBound(nums , sum , sIdx, target, lftIdx, ritIdx);
//         result = (Idx)
//     }
        
//     return 0;
// }
