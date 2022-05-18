# include <iostream>
# include <stack>         
# include <vector>     
# include <queue>       
using namespace std;

int main (){
    int a[2][2] = {1,2,3,4};
    int b[2] = {0,1};
    cout << *(*(a) + 1); // 4
    cout << endl;
    cout << *(a+1); //0xafb29ffaa8
    cout << endl;
    cout << a+1;
    cout << endl;
    cout << *b; // 0
    cout << &*b; // 0
    return 0;
}