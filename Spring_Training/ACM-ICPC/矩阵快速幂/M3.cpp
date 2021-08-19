/**
例题：Matrix Power Series_POJ 3233

*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

//用二维vector来表示矩阵
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

int MOD;

//计算A*B
mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for(int i=0; i<A.size(); i++)
        for(int k=0; k<B.size(); k++)
            for(int j=0; j<B[0].size(); j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}

//计算A^n
mat pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for(int i=0; i<A.size(); i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1)
            B=mul(B, A);
        A=mul(A, A);
        n>>=1;
    }
    return B;
}


int n, k;


int main()
{
    scanf("%d%d%d", &n, &k, &MOD);
    mat A(n, vec(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &A[i][j]);


    mat B(n*2, vec(n*2));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            B[i][j]=A[i][j];
        }
        B[n+i][i]=B[n+i][n+i]=1;
    }
    B=pow(B, k+1); //I+A+A^2...+A^k
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int a=B[n+i][j]%MOD;
            //减去I
            if(i==j)
                a=(a+MOD-1)%MOD;
            printf("%d%c", a, j+1==n? '\n':' ');
        }



    return 0;
}
