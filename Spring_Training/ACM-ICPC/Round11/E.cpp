#include <bits/stdc++.h>
using namespace std;

int x, k;
double p;
double dp1[407];
double dp2[407];

int main()
{
    scanf("%d%d%lf", &x, &k, &p);

    for(int i=0; i<k+1; i++)
    {
        for(int j=x+i; j%2==0; j/=2)
        {
            dp1[i]++;
        }
    }

    bool flag=true;
    for(int i=0; i<k; i++)
    {
//        cout<<i<<":"<<endl;
//        for(int i=0; i<2*k+2; i++)
//            printf("%.2lf ", dp1[i]);
//        printf("\n");
//        for(int i=0; i<2*k+2; i++)
//            printf("%.2lf ", dp2[i]);
//        printf("\n");

        if(flag)
        {
            memset(dp2, 0, sizeof(dp2));
            for(int j=0; j<k+1;  j++)
            {
                dp2[j*2]+=(dp1[j]+1)*(p/100);
                dp2[j]+=dp1[j+1]*(100-p)/100;
            }
            flag=false;
        }
        else
        {
            memset(dp1, 0, sizeof(dp1));
            for(int j=0; j<k+1;  j++)
            {
                dp1[j*2]+=(dp2[j]+1)*(p/100);
                dp1[j]+=dp2[j+1]*(100-p)/100;
            }
            flag=true;
        }
    }


//    cout<<k<<":"<<endl;
//    for(int i=0; i<2*k+2; i++)
//        printf("%.2lf ", dp1[i]);
//    printf("\n");
//    for(int i=0; i<2*k+2; i++)
//        printf("%.2lf ", dp2[i]);
//    printf("\n");



    if(flag)
    {
        printf("%.13lf\n", dp1[0]);
    }
    else
    {
        printf("%.13lf\n", dp2[0]);
    }


    return 0;
}
