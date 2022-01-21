// 输入：nums = [0,1,2,2,3,0,4,2], val = 2
// 输出：5, nums = [0,1,4,0,3]
// 解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。

# include <iostream>
# include <vector>
using namespace std;
int main() {
    int nums[8] = {0,1,2,2,3,0,4,2};
    int val = 2;

//法一： 交换（暴力）
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

// 法二： 双指针法
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

