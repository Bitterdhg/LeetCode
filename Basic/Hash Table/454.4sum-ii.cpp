// // �����ĸ��������� nums1��nums2��nums3 �� nums4 ��
// // ���鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺

// // �Խ�1��

// // �������ʱ 21 / 132

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

// // ������
// // ������ÿ�������п������ظ� �Һ���λ�ò�ͬ����������unordered_map���ݽṹ
// // ǰ��������ı���ö�� �����еĿ����� ���һ��������unordered_map����
// // ��ʱ��57 / 132

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
//     // nums4 (value , ���ִ���)
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


// // �Խ������������ʾ
// // ������Ҫ����������ԣ���������� ������mapȥװ��map(value , times�����ִ�����)
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

//     // ����map1
//     // map (value , times)
    
//     for (auto & iter1 : map1) {
//         value = iter1.first;
//         auto iter2 = map2.find( - value);
//         // found
//         if (iter2 != map2.end()) {
//             result += (iter1.second * (iter2 -> second)); // ??? ��֪��ôд
//         }
//     }

//     // out
//     cout << result;

//     return 0;  
// } 

// ��⣺
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