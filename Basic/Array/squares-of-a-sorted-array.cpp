// ����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��
// дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��

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
//������ʱ�临�Ӷȣ�O��n��
    // def
        int length = 5;
        int min = 1e8 + 1;
        int minIndex = -1;

        int leftIndex = -1;
        int rightIndex = -1;
        int resultIndex = -1;
        int result[5];
        // 1. Ѱ����Сֵ �� Ȼ��������λ��
        for (int i = 0; i <= length-1 ; i++){
            // 1.1 square
            nums[i] = nums[i] * nums[i];
            // 1.2 find MIN
            if (min > nums[i]){
                min = nums[i];
                minIndex = i;
            }
        }

        // 2. �ֱ� ����search С�ķ����µ�������
        // 2.1 �ȵ���β
        leftIndex = minIndex - 1;
        rightIndex = minIndex + 1;
        result[0] = min;
        for (resultIndex = 1; (rightIndex <= length-1) && (leftIndex >= 0); ){ //resultIndex ��¼��ǰResult��index
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
        // 2.2 �󵽽�β
        if (rightIndex <= length-1){ // 2.2.1 Rightû��ͷ
            for ( ; resultIndex<= length-1 ;){
                result[resultIndex] = nums[rightIndex];
                resultIndex++;
                rightIndex++;
            }
        }else{ // // 2.2.2 Leftû��ͷ
            for( ; resultIndex<= length-1 ;){
                result[resultIndex] = nums[leftIndex];
                resultIndex ++;
                leftIndex --;
            } 
        }// if (rightIndex <= length-1)

        // 3. ��� ����µ�����
        for(int i = 0 ; i <= length-1; i++){
            cout << result[i] << " ";
        }
        return 0;
}