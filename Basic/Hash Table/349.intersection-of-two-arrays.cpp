// ������������ nums1 �� nums2 ������ ���ǵĽ��� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ�
// ���ǿ��� ��������������˳�� ��

// �Խ�1������
// # include <iostream>
// # include <vector>
// # include <cmath>
// using namespace std;

// int hashFunc (int x) {
//     return x;
// }

// int main() {
//     int nums1[3] = {4,9,5};
//     int nums2[5] = {9,4,9,8,4};
    
//     // def
//     vector <int> cout1(1001, 0);
//     vector <int> cout2(1001, 0);
//     vector <int> result;
//     int len1 = 3;
//     int len2 = 5;
//     // int len1 = nums1.size();
//     // int len2 = nums2.size();

//     // cout
//     for (int i = 0; i < len1; i++) {
//         cout1[hashFunc(nums1[i])] ++;
//     }
//     for (int i = 0; i < len2; i++) {
//         cout2[hashFunc(nums2[i])] ++;
//     }

//     // out
//     for (int i = 0; i <= 1000; i++) {
//         if (cout1[i] != 0 && cout2[i] != 0) {
//             result.push_back(i);
//         }
//     }
//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << " "; 
//     }
//     return 0;
// }

// ���1��unordered_set 
# include <iostream>
# include <vector>
# include <cmath>
# include <unordered_set>
using namespace std;

int hashFunc (int x) {
    return x;
}

int main() {
    int a[3] = {4,9,5};
    int b[5] = {9,4,9,8,4};

    vector <int> nums1(a, a + 3);
    vector <int> nums2(b, b + 5);
    
    // def
    unordered_set<int> result_set; // ��Ž��
    unordered_set<int> nums_set(nums1.begin(), nums1.end());

    // for ( Ҫ�������������� �������� �� �������� )

    for (int num : nums2) {
        // ����nums2��Ԫ�� ��nums_set���ֳ��ֹ�

        // nums_set.find(num) : ����ֵ�������ҵ�Ԫ�صĵ����������򷵻�ָ��unordered_setĩβ�ĵ�������
        if (nums_set.find(num) != nums_set.end()) {
            result_set.insert(num);
        }
    }
    for (auto iter = result_set.begin(); iter != result_set.end(); ++iter) {
        cout << *iter << " ";
    }
    return 0;
}