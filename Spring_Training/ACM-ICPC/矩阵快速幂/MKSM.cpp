///   https://blog.csdn.net/wust_zzwh/article/details/52058209

const int MAX_N=10;

void multi(int a[][MAX_N],int b[][MAX_N],int n)
{
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
        tmp[i][j]+=a[i][k]*b[k][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        a[i][j]=tmp[i][j];
}



int res[MAX_N][MAX_N];
void Pow(int a[][MAX_N],int n)
{
    memset(res,0,sizeof res);
    for(int i=1;i<=n;i++) res[i][i]=1;
    while(n)
    {
        if(n&1)
            multi(res,a,n);//res=res*a;复制直接在multi里面实现了；
        multi(a,a,n);//a=a*a
        n>>=1;
    }
}
