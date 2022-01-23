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
// Approach : two-poniter ʱ�临�Ӷȣ�O��n����
    //def 
    int length = 5; 
    int result[5];
    
    int leftPoniter = 0;
    int rightPointer = length - 1;
    int resultIndex = length - 1;
    //1. left right search
    for( ; leftPoniter <= rightPointer ; resultIndex-- ){
            if (nums[leftPoniter] * nums[leftPoniter] > nums[rightPointer] * nums[rightPointer]){
                result[resultIndex] = nums[leftPoniter] * nums[leftPoniter];
                leftPoniter ++;
            }else{
                result[resultIndex] = nums[rightPointer] * nums[rightPointer];
                rightPointer --;
            }// if (left > right)
    }
    // 3. ��� ����µ�����
    for(int i = 0 ; i <= length-1; i++){
        cout << result[i] << " ";
    }
    return 0;
}