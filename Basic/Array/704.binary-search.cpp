// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// [-1,0,3,5,9,12]
// 9
// [-1,0,3,5,9,12]
// 2
# include <iostream>
# include <vector>
using namespace std;

int main() {
    // def
    int nums[6] = {-1,0,3,5,9,12}, target = 2;
    int left = 0 ,right = 5;
    int mid = 0;
    while (left <= right){
        // 2分
        mid = (left + right) / 2;
        // search
        // seach right 
        if (nums[mid] < target) left = mid + 1;
        // seach left
        else if (nums[mid] > target) right = mid - 1;
        // find it
        else {cout << mid;return 0;}
    }
    // not find
    cout << -1;
    return 0;
}
