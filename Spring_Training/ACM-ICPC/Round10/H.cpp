#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for(int i=0; i<A.size(); i++)
        for(int k=0; k<B.size(); k++)
            if(A[i][k])//此处作一个判断，应对稀疏矩阵问题
                for(int j=0; j<B[0].size(); j++)
                    C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
    return C;
}

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

int n, m, k;

int main()
{
    while(scanf("%d%d%d", &n, &m, &k)!=EOF)
    {
        if(n==0 && m==0 && k==0)
            break;

        mat a(1, vec(n+1));
        a[0][0]=1;

        mat b(n+1, vec(n+1));
        for(int i=0; i<n+1; i++)
            b[i][i]=1;
        while(k--)
        {
            getchar();
            char type=getchar();
            if(type=='g')
            {
                int in;
                scanf("%d", &in);
                b[0][in]++;
            }
            else if(type=='e')
            {
                int in;
                scanf("%d", &in);
                for(int i=0; i<n+1; i++)
                    b[i][in]=0;
            }
            else
            {
                int in1, in2;
                scanf("%d%d", &in1, &in2);
                for(int i=0; i<n+1; i++)
                    swap(b[i][in1], b[i][in2]);
            }
        }

        b=pow(b, m);

        a=mul(a, b);

        for(int i=1; i<=n; i++)
        {
            if(i!=1)
                printf(" ");
            printf("%lld", a[0][i]);
        }
        printf("\n");

    }



    return 0;
}
