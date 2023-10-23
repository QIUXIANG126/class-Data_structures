#include <iostream>
using namespace std;

int GCD(int A ,int B){
    int R=A%B;
    if(R==0){
        return B;
    }else{
        return GCD(B,A%B);
    }
}
int main(){
    int A,B,R;
    cout << "輸入兩個自然數A, B:" << endl;
    cin >> A >> B;
    while(R= A%B){
        A=B;
        B=R;
    }
    cout << "最大公因數= " << B;
}