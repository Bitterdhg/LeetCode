// ����һ���������� nums?��һ������Ŀ��ֵ target��
// �����ڸ��������ҳ� ��ΪĿ��ֵ target? ����?����?���������������ǵ������±ꡣ

// ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

// ����԰�����˳�򷵻ش𰸡�

// ��һ������
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

// ������unoedered_map
// ����������nums������һ��x �����ж���target - x��set���� �� 
// ��: insert x������������
// ��: ���������

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

    // ����
    for (int i = 0; i < nums.size(); i ++) {
        auto iter = map.find(target - nums[i]); // find `iter -> second` �� key
        if (iter != map.end()) { // found
            cout << i << " " << iter -> second;
            return 0;
        } else {
            map.insert(pair <int, int> (nums[i], i));
        }
    }
    return 0;
}