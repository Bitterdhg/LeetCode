//������С�� ���������� 
//��������ڷ��������������飬���� 0 ��
# include <iostream>
# include <vector>
using namespace std;
// Approach 1 : ������
// int main() {
        //def
        // vector<int> nums = {1,1,1,1,1,1,1,1};
        // int target = 11;
        // int length = nums.size();

//         int result = INT32_MAX; // ���յĽ��
//         int sum = 0; // �����е���ֵ֮��
//         int subLength = 0; // �����еĳ���
//         for (int i = 0; i < nums.size(); i++) { // �������������Ϊi
//             sum = 0;
//             for (int j = i; j < nums.size(); j++) { // ������������ֹλ��Ϊj
//                 sum += nums[j];
//                 if (sum >= target) { // һ�����������кͳ�����target������result
//                     subLength = j - i + 1; // ȡ�����еĳ���
//                     result = result < subLength ? result : subLength;
//                     break; // ��Ϊ�������ҷ���������̵������У�����һ������������break
//                 }
//             }
//         }
//         // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
//         result = (result == INT32_MAX) ? 0 : result;
//         cout << result;
//         return 0;
// }

// Approach 2 : ˫ָ�루���е���ʽ��
// int main() {
//     vector<int> nums = {2,3,1,2,4,3};
//     int target = 7;
//     int length = nums.size();

//     int result = INT32_MAX;
//     int sum = 0; // ����������ֵ֮��
//     int i = 0; // ����������ʼλ��
//     int subLength = 0; // �������ڵĳ���
//     for (int j = 0; j < nums.size(); j++) {
//         sum += nums[j]; // j��ʾ��ǰ�����еĽ���λ��
//         // ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
//         while (sum >= target) {
//             subLength = (j - i + 1); // ȡ�����еĳ���
//             result = (result < subLength) ? result : subLength;
//             sum -= nums[i]; // �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
//             i++;
//         }
//     }
//     // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
//     result = (result == INT32_MAX) ? 0 : result;
//     cout << result;
//     return 0;
// } 

// �Լ�д�� ˫ָ��
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
    //     // 1.1 ��ȷ�� β���ӣ�sIdx���� ��eIdx���ӣ�
    //     for (eIdx = 0; eIdx <= upBd ;eIdx++) { // eIdx : ��ǰsubarray ��β�±�
    //         sum += nums[eIdx];
    //         // 1.1.1����target //������ β�̶���sIdx���� ��eIdx���䣩
    //         while (sum >= target) { 
    //             // 1.1.1.1 judege �Ƿ�update sublenth
    //             if ((eIdx - sIdx + 1) < subLength) {
    //                 subLength = eIdx - sIdx + 1;
    //             }
    //             // 1.1.1.2 һ���������
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

//Approach 3:ǰ׺�� + ���ֲ���
// ʱ�临�Ӷȣ���ʱ�临�Ӷ���O(nlogn)

// Todo upperbound


int main() {
    int nums[6] = {2,3,1,2,4,3};
    int target = 7;
    int length = 6;

    // int nums[3] = {1,4,4};
    // int target = 1;
    // int length = 3;
    // def
    
    int i;
    int upbd = length - 1; 
    int sum[100000 + 1];
    // 1. ǰ׺��
    sum[0] = 0;
    for (i = 1; i <= upbd + 1; i++) { // sum[1]��ʾǰ1��ǰ׺��
        sum[i] += (sum[i - 1] + nums[i - 1]);
    }
    // for (i = 0 ; i <= upbd + 1 ;i++) cout<< sum[i] << " ";
    //0 2 5 6 8 12 15

    // 2. binary search
    int lftIdx = 0;
    int ritIdx = upbd + 1;
    int midIdx;
    int sIdx = 0;
    int result = 100001;
    int Idx = 0;
    // for (sIdx = 1 ;sIdx <= upbd ;sIdx++) { // sIdx �Ƕ���
    //0 2 5 6 8 12 15
    for (sIdx = 0 ;sIdx <= upbd + 1; sIdx++) { // sIdx �Ƕ���
        // binary search
        ritIdx = upbd + 1;
        lftIdx = 0;
        while (lftIdx < ritIdx) { // ����[)
            midIdx = (ritIdx + lftIdx) / 2;
            if (sum[midIdx] - sum[sIdx] < target) { // > target midIdex���ұ߼��䱾��
                lftIdx = midIdx + 1;
            } else { // if (target < sum[midIdx] - sum[sIdx])
                ritIdx = midIdx;
            }
        }
        cout << sum[midIdx] - sum[sIdx] << " ";
        // ���ж��Ƿ� ���0
        if (sum[midIdx] - sum[sIdx] >= target && midIdx - sIdx < result) {
            result = midIdx - sIdx;
        }
    }
    result = (result == 100001) ? 0 : result;
    cout << result;
    return 0;
}
