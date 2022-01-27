// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// [-4,-1,0,3,10]
// [0,1,9,16,100]

// [-7,-3,2,3,11]
// [4,9,9,49,121]
# include <iostream>
# include <vector>
using namespace std;
// 方法一：双指针法（从外到内）
// int main(){
//     int nums[5] =  {-4,-1,0,3,10} ; 
// // Approach : two-poniter 时间复杂度（O（n））
//     //def 
//     int length = 5; 
//     int result[5];
    
//     int leftPoniter = 0;
//     int rightPointer = length - 1;
//     int resultIndex = length - 1;
//     //1. left right search
//     for( ; leftPoniter <= rightPointer ; resultIndex-- ){
//             if (nums[leftPoniter] * nums[leftPoniter] > nums[rightPointer] * nums[rightPointer]){
//                 result[resultIndex] = nums[leftPoniter] * nums[leftPoniter];
//                 leftPoniter ++;
//             }else{
//                 result[resultIndex] = nums[rightPointer] * nums[rightPointer];
//                 rightPointer --;
//             }// if (left > right)
//     }
//     // 3. 最后 输出新的数组
//     for(int i = 0 ; i <= length-1; i++){
//         cout << result[i] << " ";
//     }
//     return 0;
// }

// 方法二：直接暴力（超时）
// int main() {
//     // 按照绝对值 重新排列
//     vector <int> nums {-4,-1,0,3,10} ; 
//     // def
//     int length = nums.size() , right_bound = nums.size() - 1;

//     // 1. square
//     for (int i = 0 ; i <= length-1 ;i++ ){
//         nums[i] = nums[i] * nums[i];
//     }
//     // 2. sort
//     for (bool sort = false ; (sort = !sort) ; right_bound--){
//         for (int i = 0; i <= right_bound-1 ; i++){
//             if (nums[i] > nums[i+1]){
//                 swap(nums[i] , nums[i+1]);
//                 sort = false;
//             }
//         }
//     }
//     for (int i = 0; i <= length - 1; i++) {
//         cout << nums[i] << " "; 
//     }
    
// }

// 法三：自己想的双指针（从中间往两边找）
// 时间复杂度 O（n）

int main() {
    vector <int> nums {-4,-1,0,3,10} ; 
    // def
    int length = nums.size();
    int min = 1e8 + 1;
    int minI = -1;

    int leftI = -1;
    int rightI = -1;
    int Result_i = -1;
    vector<int> Result(length, 0);
    // 1. 寻找最小值 ， 然后标记它的位置
    for (int i = 0; i <= length-1 ; i++){
        // 1.1 square
        nums[i] = nums[i] * nums[i];
        // 1.2 find MIN
        if (min > nums[i]){
            min = nums[i];
            minI = i;
        }
    }

    // 2. 分别 左右search 小的放入新的数组里
    // 2.1 先到结尾
    leftI = minI - 1;
    rightI = minI + 1;
    Result[0] = min;
        for (Result_i = 1; (rightI <= length-1) && (leftI >= 0); ){ //Result_i 记录当前Result的index
        if(nums[leftI] <= nums[rightI]){
            Result[Result_i] = nums[leftI];
            Result_i++;
            leftI --;
        }
        else{
            Result[Result_i] = nums[rightI];
            Result_i++;
            rightI++;
        }
    }
    // 2.2 后到结尾
    if (rightI <= length-1){ // 2.2.1 Right没到头
        for ( ; Result_i<= length-1 ;){
            Result[Result_i] = nums[rightI];
            Result_i++;
            rightI++;
        }
    }
    else{ // // 2.2.2 Left没到头
        for( ; Result_i<= length-1 ;){
            Result[Result_i] = nums[leftI];
            Result_i++;
            leftI --;
        } 
    }
    // 3. 最后 输出新的数组
    for (int i = 0; i <= length - 1; i++) {
        cout << Result[i] << " "; 
    }
    return 0;
}