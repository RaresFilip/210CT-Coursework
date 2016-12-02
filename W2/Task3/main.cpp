#include <iostream>

using namespace std;

void read_mat(int n, int a[20][20])
{
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
}

void mat_addition (int n, int a[20][20], int b[20][20], int c[20][20])
{
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=a[i][j]+b[i][j];
}

void mat_subtraction (int n, int a[20][20], int b[20][20], int c[20][20])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j] = a[i][j] - b[i][j];
}

void mat_multiplication (int n, int a[20][20], int b[20][20], int c[20][20])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                c[i][j] += a[i][k] * b[k][j];
}

void scal_multiplication (int n, int a[20][20], int k)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = a[i][j] * k;
}

void write_mat (int n, int a[20][20])
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n";
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
    }
}

int main()
{
    int n, A[20][20],B[20][20],C[20][20],D[20][20],E[20][20];

    cout<<"Insert the order number of the matrices: ";
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            D[i][j] = E[i][j] = 0;

    cout<<"Insert matrix B: \n";
    read_mat(n,B);
    cout<<"Insert matrix C: \n";
    read_mat(n,C);

    //multiplication of matrices B and C in D
    mat_multiplication(n,B,C,D);
    //addition of matrices B and C in E
    mat_addition(n,B,C,E);
    //multiplication of the matrix E with 2
    scal_multiplication(n,E,2);
    //subtraction of matrices D and E
    mat_subtraction(n,D,E,A);
    //the result of the computation
    write_mat(n,A);

    return 0;
}
