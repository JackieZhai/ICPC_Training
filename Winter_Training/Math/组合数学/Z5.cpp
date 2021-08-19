/*
加练题：Paths on a Grid_POJ 1942
	并不是用杨辉三角求组合数。 
*/
#include <iostream>

using namespace std;
unsigned long long c(unsigned long long x,unsigned long long y)
{
    unsigned long long s=1,i,j;
    for (i = y + 1, j = 1; i <= x; i++, j++)
    {
        s = s * i / j;
    }
    return s;
}

int main()
{
    unsigned long long n,m,x;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        {
            break;
        }
        x=n;
        if(x<m)x=m;
        cout <<c(n+m,x)<<endl;
    }
    return 0;
}

