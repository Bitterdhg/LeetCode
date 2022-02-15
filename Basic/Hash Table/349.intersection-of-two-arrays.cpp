// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。
// 我们可以 不考虑输出结果的顺序 。

// 自解1
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

int hashFunc (int x) {
    return x;
}

int main() {
    int nums1[3] = {4,9,5};
    int nums2[5] = {9,4,9,8,4};
    
    // def
    vector <int> cout1(1001, 0);
    vector <int> cout2(1001, 0);
    vector <int> result;
    int len1 = 3;
    int len2 = 5;
    // int len1 = nums1.size();
    // int len2 = nums2.size();

    // cout
    for (int i = 0; i < len1; i++) {
        cout1[hashFunc(nums1[i])] ++;
    }
    for (int i = 0; i < len2; i++) {
        cout2[hashFunc(nums2[i])] ++;
    }

    // out
    for (int i = 0; i <= 1000; i++) {
        if (cout1[i] != 0 && cout2[i] != 0) {
            result.push_back(i);
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; 
    }
    return 0;
}