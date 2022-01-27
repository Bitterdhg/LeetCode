// ����һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�

// �����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�

// ������㲢���شﵽ¥�ݶ�������ͻ��ѡ�
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main() {
    // def
    vector <int> cost {1,100,1,1,1,100,1,1,100,1}; 
    vector <int> dp(cost.size(), 0);
    int i;
    int choose = -1;
    int upbd = cost.size() - 1;
    // 1. ����
    // dp[i] ��i��¥�ݵ���Сcost 
    // 2. initial
    dp[0] = cost[0];
    dp[1] = cost[1]; // ��Ϊdp[1] < dp[0] + dp[1]
    // 3. formulate
    for (i = 2; i <= upbd ; i++) {
        choose = (dp[i - 1] > dp[i - 2]) ? (i-2) : (i-1);
        dp[i] = dp[choose] + cost[i];
    }
    cout << min(dp[upbd], dp[upbd - 1]);
    return 0;
}