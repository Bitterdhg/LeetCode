// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// [-4,-1,0,3,10]
// [0,1,9,16,100]

// [-7,-3,2,3,11]
// [4,9,9,49,121]
# include <iostream>
# include <vector>
using namespace std;

int main(){
    int nums[5] =  {-4,-1,0,3,10} ; 
//Approach 2:
//分析：时间复杂度：O（n）
    // def
        int length = 5;
        int min = 1e8 + 1;
        int minIndex = -1;

        int leftIndex = -1;
        int rightIndex = -1;
        int resultIndex = -1;
        int result[5];
        // 1. 寻找最小值 ， 然后标记它的位置
        for (int i = 0; i <= length-1 ; i++){
            // 1.1 square
            nums[i] = nums[i] * nums[i];
            // 1.2 find MIN
            if (min > nums[i]){
                min = nums[i];
                minIndex = i;
            }
        }

        // 2. 分别 左右search 小的放入新的数组里
        // 2.1 先到结尾
        leftIndex = minIndex - 1;
        rightIndex = minIndex + 1;
        result[0] = min;
        for (resultIndex = 1; (rightIndex <= length-1) && (leftIndex >= 0); ){ //resultIndex 记录当前Result的index
            if(nums[leftIndex] <= nums[rightIndex]){
                result[resultIndex] = nums[leftIndex];
                resultIndex ++;
                leftIndex --;
            }else{
                result[resultIndex] = nums[rightIndex];
                resultIndex ++;
                rightIndex ++;
            }//if(nums[leftIndex] <= nums[rightIndex])
        }
        // 2.2 后到结尾
        if (rightIndex <= length-1){ // 2.2.1 Right没到头
            for ( ; resultIndex<= length-1 ;){
                result[resultIndex] = nums[rightIndex];
                resultIndex++;
                rightIndex++;
            }
        }else{ // // 2.2.2 Left没到头
            for( ; resultIndex<= length-1 ;){
                result[resultIndex] = nums[leftIndex];
                resultIndex ++;
                leftIndex --;
            } 
        }// if (rightIndex <= length-1)

        // 3. 最后 输出新的数组
        for(int i = 0 ; i <= length-1; i++){
            cout << result[i] << " ";
        }
        return 0;
}