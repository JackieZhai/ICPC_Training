#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double a1[1000010],a2[1000010];
double sum;
double s(double x1,double y1,double x2,double y2)
{
    double p,a,b,c;
    a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    b=sqrt(pow(a1[0]-x2,2)+pow(a2[0]-y2,2));
    c=sqrt(pow(x1-a1[0],2)+pow(y1-a2[0],2));
    p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool shun(double x1,double y1,double x2,double y2,double x3,double y3)
{
    int y;
    y=(y2-y1)*(x3-x1)/(x2-x1)+y1;
    return y3>=y1;
}


int main()
{
    int n,i,j;
    bool s1;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        sum=0;
        for(i=0;i<=n-1;i++)
            scanf("%lf %lf",&a1[i],&a2[i]);
        if(n==1 || n==2)
            printf("0\n");
        else
        {
            s1=shun(a1[0],a2[0],a1[1],a2[1],a1[n-1],a2[n-1]);
            for(i=2;i<=n-1;i++)
            {
                if(i!=n-1)
                {
                    if(shun(a1[0],a2[0],a1[i+1],a2[i+1],a1[i],a2[i])^shun(a1[0],a2[0],a1[i-1],a2[i-1],a1[i],a2[i]))
                        sum+=s(a1[i-1],a2[i-1],a1[i],a2[i]);
                    else
                        sum-=s(a1[i-1],a2[i-1],a1[i],a2[i]);
                }
                else
                {
                    if(shun(a1[0],a2[0],a1[1],a2[1],a1[i],a2[i])^shun(a1[0],a2[0],a1[i-1],a2[i-1],a1[i],a2[i]))
                        sum+=s(a1[i-1],a2[i-1],a1[i],a2[i]);
                    else
                        sum-=s(a1[i-1],a2[i-1],a1[i],a2[i]);
                }

            }
            printf("%d\n",-(int)floor(sum+0.5));
        }
    }

    return 0;
}
