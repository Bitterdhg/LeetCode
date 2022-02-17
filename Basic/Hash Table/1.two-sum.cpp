// 给定一个整数数组 nums?和一个整数目标值 target，
// 请你在该数组中找出 和为目标值 target? 的那?两个?整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案。

// 法一：暴力
// # include <iostream>
// # include <vector>
// # include <cmath>
// # include <unordered_set>
// using namespace std;
// int main(){
//     vector <int> nums {3,2,4};
//     int target = 6;

//     // def
//     for (int i = 0; i < nums.size() - 1; i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if (nums[i] + nums[j] == target) {
//                 cout << i << " " << j;
//                 return 0;
//             } else {
//                 continue;
//             }
//         }
//     }
//     return 0;
// }

// 法二：unoedered_map
// 分析：遍历nums，碰到一个x 首先判断它target - x在set有无 ； 
// 无: insert x，继续遍历；
// 有: 输出，结束

# include <iostream>
# include <vector>
# include <cmath>
# include <unordered_map>
using namespace std;
int main(){
    int num[3] = {3,2,4};
    vector <int> nums (num, num + 3);
    int target = 6;

    // def
    unordered_map <int, int> map;

    // 遍历
    for (int i = 0; i < nums.size(); i ++) {
        auto iter = map.find(target - nums[i]); // find `iter -> second` 即 key
        if (iter != map.end()) { // found
            cout << i << " " << iter -> second;
            return 0;
        } else {
            map.insert(pair <int, int> (nums[i], i));
        }
    }
    return 0;
}