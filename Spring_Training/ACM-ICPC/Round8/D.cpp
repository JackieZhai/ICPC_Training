#include <bits/stdc++.h>
using namespace std;

const double eps=1e-12;

int n, T;
double ans;
double p[5007];
int t[5007];

void dfs(int x, int r, int c, double m, int sub)
{
    cout<<"OK "<<x<<" "<<r<<" "<<c<<" "<<m<<" "<<sub<<endl;

    if(m<eps)
        return ;
    if(x==n || r==0)
    {
        ans+=c*m;
        return ;
    }
    if(sub==t[x])
    {
        dfs(x+1, r-1, c+1, m, 1);
        return ;
    }
    dfs(x+1, r-1, c+1, m*p[x], 1);
    dfs(x, r-1, c, m*(1-p[x]), sub+1);
}

int main()
{
    scanf("%d%d", &n, &T);
    for(int i=0; i<n; i++)
    {
        scanf("%lf%d", &p[i], &t[i]);
        p[i]/=100;
    }

    dfs(0, T, 0, 1, 1);

    printf("%.9lf\n", ans);




    return 0;
}


/*

43 41
65 17
95 18
19 17
95 28
65 40
68 30
58 41
13 14
55 26
82 13
19 17
59 31
54 41
6 29
48 25
75 37
59 38
50 25
22 32
57 19
51 32
40 21
41 27
73 41
11 16
47 18
93 13
45 13
4 25
91 29
82 40
20 19
95 28
9 22
14 25
80 34
96 24
11 36
38 40
53 20
63 37
70 35
8 24

*/
