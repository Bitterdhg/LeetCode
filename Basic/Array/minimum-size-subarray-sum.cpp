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
// int main() {
//         vector<int> nums = {2,3,1,2,4,3};
//         int s = 7;
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         int ans = INT_MAX;
//         vector<int> sums(n + 1, 0); 
//         // Ϊ�˷�����㣬�� size = n + 1 
//         // sums[0] = 0 ��ζ��ǰ 0 ��Ԫ�ص�ǰ׺��Ϊ 0
//         // sums[1] = A[0] ǰ 1 ��Ԫ�ص�ǰ׺��Ϊ A[0]
//         // �Դ�����
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

// ��дһ�� ǰ׺�� + ���ֲ���
// ��δд�꣡��Todo


// int lowerBound (int [] nums ,int [] sum, int sIdx, int target, int lftIdx,int ritIdx) {
//     int midIdx;
//     while (lftIdx <= ritIdx) { // ������[] 
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
//     // 1. ǰ׺��
//     sum[0] = 0;
//     for (i = 1; i <= upbd + 1; i++) { // sum[1]��ʾǰ1��ǰ׺��
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
//     for (sIdx = 0 ;sIdx <= upbd ;sIdx++) { // sIdx �Ƕ���
//         // binary search
//         // int lowerBound (int [] nums ,int [] sum, int sIdx, int target, int lftIdx,int ritIdx) 
//         Idx = lowerBound(nums , sum , sIdx, target, lftIdx, ritIdx);
//         result = (Idx)
//     }
        
//     return 0;
// }
