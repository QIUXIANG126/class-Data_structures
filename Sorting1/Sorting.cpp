#include <iostream>
using namespace std;

void Bubble_Sort(int a[],int n){
    int i,j,temp;
    bool flag = false;
    for(i = n-1; i > 0; i--){  //i是右限
        flag = false;
        for(j = 0;j < i; j++){
            if(a[j] > a[j+1]){ //左大右小
                flag = true;
                temp = a[j];   //將 a[j] 與 a[j+1] 交換
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag){
            for(j = 0; j < n; j++){
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
}

void Select_Sort(int a[], int n ){
    int i,j,max,temp;
    for(i = n-1; i > 0; i--){   // i 是右限
        max = i;                //找出範圍中 (a[0] ~ a[i]) 最大者，先假設 a[i] 最大
        for(j = i; j >= 0 ;j--){// j 由右而左掃描
            if(a[j] > a[max]){  //第 j 個大於 第 max 個
                max = j;        //  max隨時記錄最大者
            }
        }
        temp = a[max];  //將 a[i] 與 a[max] 交換
        a[max] = a[i];
        a[i] = temp;

        for(j = 0; j < n; j++){
            cout << a[j] <<" ";
        }
        cout << endl;
    }
}

void Insert_Sort( int a[], int n){  // int a[] 是傳入輸入矩陣的位址 不是複製新的矩陣進函式內
    int i, j, up;
    for(i = 1; i < n; i++){         // a[i] 是要整理的元素 (a[0] ~ a[i-1] 已經整理好)
        up = a[i];
        j = i;                      // 記錄空格位置
        while(j > 0 && a[j-1] > up){// 空格左邊的值比up大
            a[j] = a[j-1];          // 空格左邊的值往右移一格
            j--;
        }
        a[j] = up;                  // up中的值放入最後的空格

        for(j = 0; j < n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int arr1[] = {37,41,19,81,41,25,56,61,49};
    Bubble_Sort(arr1,9);
    cout << endl;
    int arr2[] = {37,61,19,41,81,25,56,41,49};
    Select_Sort(arr2,9);
    cout << endl;
    int arr3[] = {37,41,19,81,41,25,56,61,49};
    Insert_Sort(arr3,9);
}