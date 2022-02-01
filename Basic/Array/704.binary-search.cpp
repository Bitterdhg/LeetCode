// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// [-1,0,3,5,9,12]
// 9
// [-1,0,3,5,9,12]
// 2
// 

// // Approch 1 : 普通二分法
// // 综合实践复杂度： 1.5log（n）
// # include <iostream>
// # include <vector>
// using namespace std;

// int main() {
//     // def
//     int nums[6] = {-1,0,3,5,9,12}, target = 2;
//     int left = 0 ,right = 5;
//     int mid = 0;
//     while (left <= right){ // 区间：[left , mid - 1] , mid , [mid + 1, right]
//         // 2分
//         mid = (left + right) / 2;
//         // search
//         // seach right 
//         if (nums[mid] < target) left = mid + 1;
//         // seach left
//         else if (nums[mid] > target) right = mid - 1;
//         // find it
//         else {cout << mid;return 0;}
//     }
//     // not find
//     cout << -1;
//     return 0;
// }

// // Approach 2 : （Fib查找）
// // 综合时间复杂度 1.46log（n）
// # include <iostream>
// # include <vector>
// using namespace std;

// int main() {
//     // def
//     int nums[6] = {-1,0,3,5,9,12}, target = 3;
//     int left = 0 ,right = 5;
//     int mid = 0;
//     while (left <= right){ // 区间：[left , mid - 1] , mid , [mid + 1, right]
//         // 2分
//         mid = (right - left) * 0.618 + left ;
//         // search
//         // seach right 
//         if (nums[mid] < target) left = mid + 1;
//         // seach left
//         else if (nums[mid] > target) right = mid - 1;
//         // find it
//         else {cout << mid;return 0;}
//     }
//     // not find
//     cout << -1;
//     return 0;
// }

// // Approach 3：平衡版本
// # include <iostream>
// # include <vector>
// using namespace std;

// int main() {
//     // def
//     int nums[6] = {-1,0,3,5,9,12}, target = 3;
//     int left = 0 ,right = 5;
//     int mid = 0;
//     while (1 < right - left){ // 改进1！！！！！
//         //                     区间：[left, mid) [mid, right)
//         mid = (left + right) / 2 ;
//         // search
//         // seach right 
//         if (target < nums[mid]) { // search by left
//             right = mid;
//         } else {                  // search by right
//             left = mid; 
//         }
//     } //[left, left + 1)
//     cout << ((nums[left] == target) ? left : -1);
//     // not find
//     return 0;
// }

// // Approach 4: lowerBound 
// // 小于等于 target的最小值
# include <iostream>
# include <vector>
using namespace std;

int main() {
    // def
    int nums[6] = {1,1,1,1,1,1}, target = 3;
    int left = 0 ,right = 5;  // index
    int mid = 0; // index
    // 重点1
    while (left < right){ // 区间：[left, mid) [mid, right)
        //                     
        mid = (left + right) / 2;
        // search
        // 重点2
        if (target < nums[mid]) { // search by left
            right = mid;
        } else {                  // search by right
            left = mid + 1; 
        }
    } //left = right
    // 重点3
    cout << "小于等于 target 的最大值：" << nums[left - 1] << endl; // 没有特别很想明白为啥-1
    cout << "小于等于 target 的index：" << left - 1 << endl;
    cout << "大于target 的最小值：" << nums[left] << endl;
    cout << "大于target 的index：" << left;
    // not find
    return 0;
}

// Approach 5: upperbound
// 小于等于 target的最小值
# include <iostream>
# include <vector>
using namespace std;

int main() {
    // def
    int nums[6] = {3,5,6,7,8,10}, target = 6;
    int left = 0 ,right = 5;  // index
    int mid = 0; // index
    // 重点1
    while (left < right){ // 区间：[left, mid) [mid, right)
        //                     
        mid = (left + right) / 2;
        // search
        // 重点2
        if (target <= nums[mid]) { // search by left
            right = mid;
        } else {                  // search by right
            left = mid + 1; 
        }
    } //left = right
    // 重点3
    cout << "小于 target 的最大值：" << nums[left - 1] << endl; // 没有特别很想明白为啥-1
    cout << "小于 target 的index：" << left - 1 << endl;
    cout << "大于等于target 的最小值：" << nums[left] << endl;
    cout << "大于等于target 的index：" << left;
    // not find
    return 0;
}