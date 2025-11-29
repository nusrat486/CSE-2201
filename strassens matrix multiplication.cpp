#include <bits/stdc++.h>
using namespace std;

// add two 2x2 matrices
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] + B[i][j];
}

// subtract two 2x2 matrices
void sub(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j])
            C[i][j] = A[i][j] - B[i][j];
}

// multiply two 2x2 matrices (normal way)
void mul2(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++) {
            C[i][j] = 0;
            for(int k=0;k<2;k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[4][4], B[4][4], C[4][4];

    cout<<"Input 4x4 Matrix A:\n";
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>A[i][j];

    cout<<"Input 4x4 Matrix B:\n";
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>B[i][j];

    // divide A into 2x2 blocks
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];
        }

    // create temp matrices
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2];
    int M5[2][2], M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];

    // M1 = (A11 + A22) * (B11 + B22)
    add(A11, A22, temp1);
    add(B11, B22, temp2);
    mul2(temp1, temp2, M1);

    // M2 = (A21 + A22) * B11
    add(A21, A22, temp1);
    mul2(temp1, B11, M2);

    // M3 = A11 * (B12 - B22)
    sub(B12, B22, temp1);
    mul2(A11, temp1, M3);

    // M4 = A22 * (B21 - B11)
    sub(B21, B11, temp1);
    mul2(A22, temp1, M4);

    // M5 = (A11 + A12) * B22
    add(A11, A12, temp1);
    mul2(temp1, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    sub(A21, A11, temp1);
    add(B11, B12, temp2);
    mul2(temp1, temp2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    sub(A12, A22, temp1);
    add(B21, B22, temp2);
    mul2(temp1, temp2, M7);

    // Now construct C blocks
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, temp1);
    sub(temp1, M5, temp2);
    add(temp2, M7, C11);

    // C12 = M3 + M5
    add(M3, M5, C12);

    // C21 = M2 + M4
    add(M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    sub(M1, M2, temp1);
    add(temp1, M3, temp2);
    add(temp2, M6, C22);

    // merge all blocks into C (4x4)
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            C[i][j] = C11[i][j];
            C[i][j+2] = C12[i][j];
            C[i+2][j] = C21[i][j];
            C[i+2][j+2] = C22[i][j];
        }

    cout<<"\nResult (C = A * B):\n";
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

