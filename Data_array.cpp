#include <iostream>
using namespace std;

void PrintArray(int list[], int n){
    for(int i=0; i<n; i++){
        cout << list[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[8] = {8, 25, 11, 26, 39, 18, 120, 50};
    PrintArray(arr,8);
    cout << "Hello world";
}