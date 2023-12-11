#include <iostream>
#include <iomanip>

using namespace std;

void PrintArray(int list[], int n){//列印一維矩陣
    for(int i=0; i<n; i++){
        cout <<setw(3) << list[i] << " ";
    }
    cout << endl;
}

void ArrayCopy(int list1[], int list2[] , int n){//矩陣複製
    for(int i=0; i<n;i++){
        list1[i]=list2[i];
    }
}

void ArrayInsert(int list1[],int n, int value, int i){//矩陣替換
    for( int index = n-1;index > i;index--){
        list1[index] = list1[index-1];
    }
    list1[i]=value;
}

void ArrayDelete(int list[], int n ,int i ){//矩陣刪除
    for(int index = i; index < n-1; index++){
        list[index] = list[index+1];
    }
    list[n-1] = 0;
}

template< typename T, size_t M, size_t N>
void printarray(T(&theArray)[M][N]){//使用模板，列印二維矩陣
    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            cout << setw(2) << theArray[y][x] << " ";
        }
        cout << endl;
    }
}

void PrintMatrix_4(int A[][4], int M, int N){//列印二維矩陣。不使用模板，傳入值範圍需固定

    for(int x=0; x<M; x++){
        for(int y=0; y<N; y++){
            cout << setw(2) << A[x][y] << " ";
        }
        cout << endl;
    }
}

void PrintMatrix_3(int A[][3], int M, int N){//同上

    for(int x=0; x<M; x++){
        for(int y=0; y<N; y++){
            cout << setw(2) << A[x][y] << " ";
        }
        cout << endl;
    }
}

void AddMatrix(int A[][3], int B[][3],int C[][3], int m, int n){//二維矩陣相加。兩矩陣大小需相同
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            C[i][j]=A[i][j] + B[i][j];
        }
    }
}

template< typename T, size_t M, size_t N>
void addmatrix(T(&A)[M][N], T(&B)[M][N], T(&C)[M][N]){
    for(int i = 0; i < M;i++){
        for(int j = 0; j < N; j++){
            C[i][j]= A[i][j]+B[i][j];
        }
    }
}

template <typename T, size_t M, size_t N, size_t O>
void multiplymatrix(T(&A)[M][N], T(&B)[N][O], T(&C)[M][O]){
    for( int i = 0; i < M; i++){
        for(int j = 0; j < O; j++){
            C[i][j]=0;
            for( int k = 0; k < N; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
float B[3][4] = {{2,3,6,8},{10,12,14,16},{18,20,22,24}};

int A1[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
int B1[4][3] = {{0,1,2},{3,4,5},{6,7,8},{9,10,11}};
int C1[4][3] = {0};
int C2[4][3] = {0};

int A2[3][2] = {{1,2,},{3,4},{5,6}};
int B2[2][4] = {{0,1,1,2,},{4,0,-1,3}};
int C22[3][4] = {0};

int main(){
    int list1[8] = {8, 25, 11, 26, 39, 18, 120, 50};
    int list2[8]={0};

    cout << "一維矩陣列印(list1): ";
    PrintArray(list1,8);
    ArrayCopy(list2,list1,8);
    cout << "矩陣複製(list1 ,list2): "; 
    PrintArray(list2,8);
    ArrayInsert(list1,8,27,3);
    cout << "矩陣取代(list2): ";
    PrintArray(list1,8);
    ArrayDelete(list2,8,3);
    cout << "矩陣刪除(list2): ";
    PrintArray(list2,8);
    cout << endl;
    cout <<"二維矩陣列印(A): "<<endl;
    PrintMatrix_4(A,3,4);
    cout << endl;
    cout <<"二維矩陣列印template(B): "<<endl;
    printarray(B);
    cout << endl;
    cout <<"二維矩陣相加(A1,B1): " <<endl;
    AddMatrix(A1,B1,C1,4,3);
    PrintMatrix_3(C1,4,3);
    cout << endl;
    cout <<"template print: "<<endl;
    printarray(C1);
    cout <<endl;
    cout <<"template add: "<<endl;
    addmatrix(A1,B1,C2);
    printarray(C2);
    cout <<endl;
    cout <<"矩陣相乘(A2,B2): "<<endl;
    multiplymatrix(A2,B2,C22);
    printarray(C22);
}