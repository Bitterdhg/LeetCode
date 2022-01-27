// 1 2 3
// 8 9 4
// 7 6 5


# include <iostream>
# include <vector>
#include <cmath>
using namespace std;
// int main() {
// Approach 1: ģ��
//     int n = 5;
//     int x = 0;
//     int y = 0;
//     int i = 1; // i��¼����˼�������
//     int times = 1; // ��¼��ǰ����timesȦ
//     int bd = n - 1;
//     vector<vector<int>> res(n, vector<int>(n, 0));
   
//    // 1. �����Χ
//     while (times <= floor(n / 2)) {
//         //1.right (0,0) -> (0, n-1) ��       y��
//         x = -1 + times;  // �����Զ�� y = x�ĺ����ϣ�����0��0�� (1,1) (2,2)
//         y = -1 + times;
//         while (y <= bd - times + 1) {
//             res[x][y] = i;
//             i++;
//             y++;
//         }
//         //2. down (1, n-1) -> (n-1, n-1) ��  x��
//         x ++;
//         y --;
//         while (x <= bd - times + 1) {
//             res[x][y] = i;
//             i++;
//             x++;
//         }
//         // 3. left (n-1, n-2) -> (n-1 , 0) �� y��
//         x --;
//         y --;
//         while (y >= 0 + times - 1) {
//             res[x][y] = i;
//             i++;
//             y--;
//         }
//         // 4.  up (n-1 , 2) -> (n-1 , 1) ��  x��
//         x --;
//         y ++;
//         while (x >= 0 + times) {
//             res[x][y] = i;
//             i++;
//             x--;
//         }
//         // 5. times++ 
//         times++;
//     }

//     // 2. ����м�
//     if (n % 2 != 0) {
//         res[times - 1][times - 1] = i;
//     }
//     // // out

//     for (int i = 0 ; i <= bd; i++) {
//         cout << endl;
//         for (int j = 0 ; j <= bd ; j++) {
//             cout << res [i][j] <<" ";
//         }
//     }
    
//     // cout << res; // �����������
//     //return res;
//     return 0;
// }

int main() { // ����������Ż��汾
    
// Approach 1: ģ��
    int n = 6;
    int x = 0;
    int y = 0;
    int i = 1; // i��¼����˼�������
    int times = 1; // ��¼��ǰ����timesȦ
    int bd = n - 1;
    vector<vector<int>> res(n, vector<int>(n, 0));
   
   // 1. �����Χ
    while (times <= floor(n / 2)) {
        //1.right (0,0) -> (0, n-1) ��       y��
        x = -1 + times;  // �����Զ�� y = x�ĺ����ϣ�����0��0�� (1,1) (2,2)
        y = -1 + times;
        while (y <= bd - times) {
            res[x][y] = i;
            i++;
            y++;
        }
        //2. down (1, n-1) -> (n-1, n-1) ��  x��
        while (x <= bd - times) {
            res[x][y] = i;
            i++;
            x++;
        }
        // 3. left (n-1, n-2) -> (n-1 , 0) �� y��
        while (y >= 0 + times) {
            res[x][y] = i;
            i++;
            y--;
        }
        // 4.  up (n-1 , 2) -> (n-1 , 1) ��  x��
        while (x >= 0 + times) {
            res[x][y] = i;
            i++;
            x--;
        }
        // 5. times++ 
        times++;
    }

    // 2. ����м�
    if (n % 2 != 0) {
        res[times - 1][times - 1] = i;
    }
    // // out

    for (int i = 0 ; i <= bd; i++) {
        cout << endl;
        for (int j = 0 ; j <= bd ; j++) {
            cout << res [i][j] <<" ";
        }
    }
    
    // cout << res; // �����������
    //return res;
    return 0;
}