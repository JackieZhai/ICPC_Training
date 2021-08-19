/**
练习题：Quad Tiling_POJ 3420
    递推式：f(n)=f(n-1)+5*f(n-2)+f(n-3)-f(n-4)
    前四项：1 5 11 36
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

//用二维vector来表示矩阵
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;


ll MOD;

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




int main()
{
    ll ansShort[]={1, 1, 5, 11, 36};
    ll n;

    mat A(4, vec(4));
    A[0][0]=1; A[0][1]=5; A[0][2]=1; A[0][3]=-1;
    A[1][0]=1; A[1][1]=0; A[1][2]=0; A[1][3]=0;
    A[2][0]=0; A[2][1]=1; A[2][2]=0; A[2][3]=0;
    A[3][0]=0; A[3][1]=0; A[3][2]=1; A[3][3]=0;
    mat B(4, vec(1));
    B[0][0]=36; B[1][0]=11; B[2][0]=5;  B[3][0]=1;

    while(scanf("%lld%lld", &n, &MOD)!=EOF)
    {
        if(n==0 && MOD==0)
            break;

        if(n<5)
        {
            printf("%lld\n", ansShort[n]%MOD);
            continue;
        }

        mat C=pow(A, n-4);
        mat D=mul(C, B);
        if(D[0][0]>0)
            printf("%lld\n", D[0][0]);
        else
            printf("%lld\n", MOD+D[0][0]); ///为什么秘制出现负数？？？
    }






    return 0;
}
