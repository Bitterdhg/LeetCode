// ����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��
// дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��

// [-4,-1,0,3,10]
// [0,1,9,16,100]

// [-7,-3,2,3,11]
// [4,9,9,49,121]
# include <iostream>
# include <vector>
using namespace std;
// ����һ��˫ָ�뷨�����⵽�ڣ�
// int main(){
//     int nums[5] =  {-4,-1,0,3,10} ; 
// // Approach : two-poniter ʱ�临�Ӷȣ�O��n����
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
//     // 3. ��� ����µ�����
//     for(int i = 0 ; i <= length-1; i++){
//         cout << result[i] << " ";
//     }
//     return 0;
// }

// ��������ֱ�ӱ�������ʱ��
// int main() {
//     // ���վ���ֵ ��������
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

// �������Լ����˫ָ�루���м��������ң�
// ʱ�临�Ӷ� O��n��

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
    // 1. Ѱ����Сֵ �� Ȼ��������λ��
    for (int i = 0; i <= length-1 ; i++){
        // 1.1 square
        nums[i] = nums[i] * nums[i];
        // 1.2 find MIN
        if (min > nums[i]){
            min = nums[i];
            minI = i;
        }
    }

    // 2. �ֱ� ����search С�ķ����µ�������
    // 2.1 �ȵ���β
    leftI = minI - 1;
    rightI = minI + 1;
    Result[0] = min;
        for (Result_i = 1; (rightI <= length-1) && (leftI >= 0); ){ //Result_i ��¼��ǰResult��index
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
    // 2.2 �󵽽�β
    if (rightI <= length-1){ // 2.2.1 Rightû��ͷ
        for ( ; Result_i<= length-1 ;){
            Result[Result_i] = nums[rightI];
            Result_i++;
            rightI++;
        }
    }
    else{ // // 2.2.2 Leftû��ͷ
        for( ; Result_i<= length-1 ;){
            Result[Result_i] = nums[leftI];
            Result_i++;
            leftI --;
        } 
    }
    // 3. ��� ����µ�����
    for (int i = 0; i <= length - 1; i++) {
        cout << Result[i] << " "; 
    }
    return 0;
}