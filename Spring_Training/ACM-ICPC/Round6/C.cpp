#include <bits/stdc++.h>
using namespace std;

const int MAXN=330;
const double eps=1e-4;

double p[MAXN][2];
double xx1, yy1, xx2, yy2;

double dis(int i, int j)
{
    return sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
}

void get_center_point(int a,int b)
{
    double x0=(p[a][0]+p[b][0])/2;
    double y0=(p[a][1]+p[b][1])/2;
    double d=sqrt(1-((p[a][0]-p[b][0])*(p[a][0]-p[b][0]) + (p[a][1]-p[b][1])*(p[a][1]-p[b][1]))/4);
    if(fabs(p[a][1]-p[b][1])<1e-6)
    {
        xx1=x0;
        yy1=y0+d;
        xx2=x0;
        yy2=y0-d;
    }
    else
    {
        double tmp=atan(-(p[a][0]-p[b][0])/(p[a][1]-p[b][1]));
        double dx=d*cos(tmp);
        double dy=d*sin(tmp);
        xx1=x0+dx;
        yy1=y0+dy;
        xx2=x0-dx;
        yy2=y0-dy;
    }
}

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
           scanf("%lf%lf", &p[i][0], &p[i][1]);

        int ans=1;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if(dis(i,j)>2.0)continue;
                get_center_point(i,j);
                int cnt=0;
                for(int i=0; i<n; i++)
                if(sqrt((p[i][0]-xx1)*(p[i][0]-xx1)+(p[i][1]-yy1)*(p[i][1]-yy1))<1+eps)
                    cnt++;
                if(cnt>ans)ans=cnt;
                cnt=0;
                for(int i=0; i<n; i++)
                    if(sqrt((p[i][0]-xx2)*(p[i][0]-xx2)+(p[i][1]-yy2)*(p[i][1]-yy2))<1+eps)
                        cnt++;
                if(cnt>ans)ans=cnt;
            }

        printf("%d\n",ans);
    }

    return 0;
}
