// // 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，
// // 数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

// // 自解1：

// // 结果：超时 21 / 132

// # include <iostream>
// # include <vector>
// using namespace std; 
// int main() {
//     vector <int> nums1 {1,2};
//     vector <int> nums2 {-2,-1};
//     vector <int> nums3 {-1,2};
//     vector <int> nums4 {0,2};

//     //def
//     int result = 0;

//     for (int i = 0; i < nums1.size(); i++) {
//         for (int j = 0; j < nums2.size(); j++) {
//             for (int k = 0; k < nums3.size(); k++) {
//                 for (int l = 0; l < nums4.size(); l++) {
//                     if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0) {
//                         result++;
//                     }
//                 }
//             }
//         }
//     }
//     cout << result;
//     return 0;  
// } 

// // 法二：
// // 分析：每个数组有可能有重复 且含有位置不同，所以运用unordered_map数据结构
// // 前三个数组的暴力枚举 到所有的可能性 最后一个数组用unordered_map查找
// // 超时：57 / 132

// # include <iostream>
// # include <vector>
// # include <unordered_map>
// using namespace std; 
// int main() {
//     vector <int> nums1 {1,2};
//     vector <int> nums2 {-2,-1};
//     vector <int> nums3 {-1,2};
//     vector <int> nums4 {0,2};

//     //def
//     int result = 0;
//     int sum = 0;
//     unordered_map <int , int> map;

//     // init nums4
//     // nums4 (value , 出现次数)
//     for (int i = 0; i < nums4.size(); i++) {
//         // not found
//         auto iter = map.find(nums4[i]);
//         if(iter == map.end()) {
//             map.insert(pair <int, int> (nums4[i], 1));
//         } else {
//             iter -> second += 1;
//         }
        
//     }

//     for (int i = 0; i < nums1.size(); i++) {
//         for (int j = 0; j < nums2.size(); j++) {
//             for (int k = 0; k < nums3.size(); k++) {
//                 sum = nums1[i] + nums2[j] + nums3[k];
//                 // found
//                 auto iter = map.find(-sum);
//                 if (iter != map.end()) {
//                     result += iter -> second;
//                 } 
//             }
//         }
//     }
//     cout << result;
//     return 0;  
// } 


// // 自解三：守题解提示
// // 分析：要不就两两配对，互相计算结果 用两个map去装，map(value , times（出现次数）)
// # include <iostream>
// # include <vector>
// # include <unordered_map>
// using namespace std; 
// int main() {
//     vector <int> nums1 {1,2};
//     vector <int> nums2 {-2,-1};
//     vector <int> nums3 {-1,2};
//     vector <int> nums4 {0,2};

//     //def
//     int result = 0;
//     int sum = 0;
//     int temp = 0;
//     int value = 0;
//     unordered_map <int , int> map1;
//     unordered_map <int , int> map2;

//     // map (value , times)
//     // init map1
//     for (int i = 0; i < nums1.size(); i++) {
//         for (int j = 0; j < nums2.size(); j++) {
//             temp  = nums1[i] + nums2[j];
//             auto iter = map1.find(temp);
//             // not found
//             if (iter == map1.end()) {
//                 map1.insert(pair <int ,int> (temp, 1));
//             // found  
//             } else {
//                 iter -> second ++;
//             }
//         }
//     }

//     // init map2
//     for (int i = 0; i < nums3.size(); i++) {
//         for (int j = 0; j < nums4.size(); j++) {
//             temp  = nums3[i] + nums4[j];
//             auto iter = map2.find(temp);
//             // not found
//             if (iter == map2.end()) {
//                 map2.insert(pair <int ,int> (temp, 1));
//             // found  
//             } else {
//                 iter -> second ++;
//             }
//         }
//     }

//     // 遍历map1
//     // map (value , times)
    
//     for (auto & iter1 : map1) {
//         value = iter1.first;
//         auto iter2 = map2.find( - value);
//         // found
//         if (iter2 != map2.end()) {
//             result += (iter1.second * (iter2 -> second)); // ??? 不知怎么写
//         }
//     }

//     // out
//     cout << result;

//     return 0;  
// } 

// 题解：
# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
int main() {
    vector <int> nums1 {1,2};
    vector <int> nums2 {-2,-1};
    vector <int> nums3 {-1,2};
    vector <int> nums4 {0,2};

    //def 
    unordered_map <int, int> umap;
    int result = 0;

    // init umap
    // umap(key , value) =  umap[value] = times 
    for (int a : nums1) {
        for (int b : nums2) {
            umap[a + b] ++;
        }
    }

    for (int c : nums3){
        for (int d : nums4) {
            // found 
            if ( umap.find (0 - (c + d)) != umap.end() ) {
                result += umap[0 - (c + d)];
            }
        }
    }
    cout << result;

    return 0;
}