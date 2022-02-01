// ����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��
// дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��

// [-1,0,3,5,9,12]
// 9
// [-1,0,3,5,9,12]
// 2
// 

// // Approch 1 : ��ͨ���ַ�
// // �ۺ�ʵ�����Ӷȣ� 1.5log��n��
// # include <iostream>
// # include <vector>
// using namespace std;

// int main() {
//     // def
//     int nums[6] = {-1,0,3,5,9,12}, target = 2;
//     int left = 0 ,right = 5;
//     int mid = 0;
//     while (left <= right){ // ���䣺[left , mid - 1] , mid , [mid + 1, right]
//         // 2��
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

// // Approach 2 : ��Fib���ң�
// // �ۺ�ʱ�临�Ӷ� 1.46log��n��
// # include <iostream>
// # include <vector>
// using namespace std;

// int main() {
//     // def
//     int nums[6] = {-1,0,3,5,9,12}, target = 3;
//     int left = 0 ,right = 5;
//     int mid = 0;
//     while (left <= right){ // ���䣺[left , mid - 1] , mid , [mid + 1, right]
//         // 2��
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

// // Approach 3��ƽ��汾
// # include <iostream>
// # include <vector>
// using namespace std;

// int main() {
//     // def
//     int nums[6] = {-1,0,3,5,9,12}, target = 3;
//     int left = 0 ,right = 5;
//     int mid = 0;
//     while (1 < right - left){ // �Ľ�1����������
//         //                     ���䣺[left, mid) [mid, right)
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
// // С�ڵ��� target����Сֵ
# include <iostream>
# include <vector>
using namespace std;

int main() {
    // def
    int nums[6] = {1,1,1,1,1,1}, target = 3;
    int left = 0 ,right = 5;  // index
    int mid = 0; // index
    // �ص�1
    while (left < right){ // ���䣺[left, mid) [mid, right)
        //                     
        mid = (left + right) / 2;
        // search
        // �ص�2
        if (target < nums[mid]) { // search by left
            right = mid;
        } else {                  // search by right
            left = mid + 1; 
        }
    } //left = right
    // �ص�3
    cout << "С�ڵ��� target �����ֵ��" << nums[left - 1] << endl; // û���ر��������Ϊɶ-1
    cout << "С�ڵ��� target ��index��" << left - 1 << endl;
    cout << "����target ����Сֵ��" << nums[left] << endl;
    cout << "����target ��index��" << left;
    // not find
    return 0;
}

// Approach 5: upperbound
// С�ڵ��� target����Сֵ
# include <iostream>
# include <vector>
using namespace std;

int main() {
    // def
    int nums[6] = {3,5,6,7,8,10}, target = 6;
    int left = 0 ,right = 5;  // index
    int mid = 0; // index
    // �ص�1
    while (left < right){ // ���䣺[left, mid) [mid, right)
        //                     
        mid = (left + right) / 2;
        // search
        // �ص�2
        if (target <= nums[mid]) { // search by left
            right = mid;
        } else {                  // search by right
            left = mid + 1; 
        }
    } //left = right
    // �ص�3
    cout << "С�� target �����ֵ��" << nums[left - 1] << endl; // û���ر��������Ϊɶ-1
    cout << "С�� target ��index��" << left - 1 << endl;
    cout << "���ڵ���target ����Сֵ��" << nums[left] << endl;
    cout << "���ڵ���target ��index��" << left;
    // not find
    return 0;
}