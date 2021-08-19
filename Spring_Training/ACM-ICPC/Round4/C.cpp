/**
线段树例题
Calculator    HDU 5238

此题要模拟一个计算器，有+、*、^三种操作
给定两种查询，1是给输入求输出、2是修改某一个运算
所有操作都要模29393
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=50007;
const int MOD=29393;

int mod[4]={7, 13, 17, 19};
int p[4][20][MOD];
int f[MAX_N<<2][4][20];
int n, m;

void init()
{
    for(int i=0; i<4; i++)
    {
        int m=mod[i];
        for(int j=0; j<m; j++)
        {
            p[i][j][0]=1;
            for(int k=1; k<MOD; k++)
            {
                p[i][j][k]=p[i][j][k-1]*j%m;
            }
        }
    }
}

void cal(int k, char op, int x)
{
    for(int i=0; i<4; i++)
    {
        int m=mod[i];
        for(int j=0; j<m; j++)
        {
            if(op=='+')
                f[k][i][j]=(j+x)%m;
            else if(op=='*')
                f[k][i][j]=(j*x)%m;
            else
                f[k][i][j]=p[i][j][x];
        }
    }
}

void build(int k, int l, int r)
{
    if(l==r)
    {
        char c;
        int x;
        scanf(" %c%d", &c, &x);
        cal(k, c, x);
        return ;
    }
    int mid=(l+r)>>1;
    int ls=k<<1;
    int rs=k<<1|1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    for(int i=0; i<4; i++)
    {
        int m=mod[i];
        for(int j=0; j<m; j++)
        {
            f[k][i][j]=f[rs][i][f[ls][i][j]];
        }
    }
}

void modify(int x, char c, int v, int k, int l, int r)
{
    if(l==r)
    {
        cal(k, c, v);
        return ;
    }
    int mid=(l+r)>>1;
    int ls=k<<1;
    int rs=k<<1|1;
    if(x<=mid)
        modify(x, c, v, ls, l, mid);
    else
        modify(x, c, v, rs, mid+1, r);
    for(int i=0; i<4; i++)
    {
        int m=mod[i];
        for(int j=0; j<m; j++)
        {
            f[k][i][j]=f[rs][i][f[ls][i][j]];
        }
    }
}


int exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x=1, y=0 ;
        return a ;
    }
    int ans=exgcd(b ,a%b ,y ,x);
    y-=a/b*x;
    return ans;
}

int crt(int v)
{
    int ans=0;
    for(int i=0; i<4; i++)
    {
        int t=MOD/mod[i] ,x ,y;
        exgcd(t, mod[i], x, y);
        ans=(ans + f[1][i][v%mod[i]]*t*(x%mod[i])) % MOD;
    }
    return (ans+MOD)%MOD;
}



int main()
{
    int T;
    scanf("%d", &T);

    init();

    for(int kase=1; kase<=T; kase++)
    {
        printf("Case #%d:\n", kase);
        scanf("%d%d", &n, &m);

        build(1, 1, n);

        while(m--)
        {
            int type, x, v;
            char c;
            scanf("%d%d", &type, &x);
            if(type==1)
            {
                printf("%d\n", crt(x));
            }
            else
            {
                scanf(" %c%d", &c, &v);
                modify(x, c, v, 1, 1, n);
            }
        }
    }




    return 0;
}
