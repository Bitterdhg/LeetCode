// ���룺nums = [0,1,2,2,3,0,4,2], val = 2
// �����5, nums = [0,1,4,0,3]
// ���ͣ�����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

# include <iostream>
# include <vector>
using namespace std;
int main() {
    int nums[8] = {0,1,2,2,3,0,4,2};
    int val = 2;

//��һ�� ������������
// record val_len
        // swap
  //  int length = 8 , val_len = 0;


    // int n = length-1; //upper_index
    // for (bool sorted = false ; sorted = !sorted ; n--){
    //     for (int i = 0; i <= n-1 ; i++){
    //         if( nums[i] == val ) {swap(nums[i], nums[i+1]); sorted = false;}
    //     }
    // }

    // for (int i=0; i<= length-1 ;i++)
    //     if (nums[i] == val)val_len++;

    // // length
    // cout << length - val_len << endl;
    // for (int i = 0; i <= length - val_len -1; i++)
    // {
    //     cout << nums[i] <<" ";
    // }
    // return 0;

// ������ ˫ָ�뷨
    //def
        // int length = nums.size();
        // int fast_pointer = 0, slow_pointer = 0;
        // remove
        // 1.1 fast_pointer
    //     for (; fast_pointer <= length-1 ;){
    //         // find val 
    //         // goal: not val and swap
    //         if (nums[fast_pointer] == val) { 
    //             fast_pointer++;
    //             //swap(nums[fast_pointer] , nums[slow_pointer]);
    //         }
    //         // not find val
    //         else{
    //             swap(nums[fast_pointer] , nums[slow_pointer]);
    //             fast_pointer++;
    //             slow_pointer++;
    //         }
    //     }
    //     // out length
    //     cout << slow_pointer-1 << endl;
    //     for (int i = 0; i <= slow_pointer-1; i++)
    // {
    //     cout << nums[i] <<" ";
    // }
    // return 0;
}

