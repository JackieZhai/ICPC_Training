#include <bits/stdc++.h>
using namespace std;


int n, m, k;


int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int px=1, py=0;
    int dir=0; //->:0,  <-:1
    for(int i=1; i<=k-1; i++)
    {
        printf("2");
        if(dir==0)
        {
            if(py+1>m)
            {
                dir=1;
                px++;
                printf(" %d %d", px, py);
            }
            else
            {
                py++;
                printf(" %d %d", px, py);
            }
        }
        else
        {
            if(py-1<1)
            {
                dir=0;
                px++;
                printf(" %d %d", px, py);
            }
            else
            {
                py--;
                printf(" %d %d", px, py);
            }
        }
        if(dir==0)
        {
            if(py+1>m)
            {
                dir=1;
                px++;
                printf(" %d %d", px, py);
            }
            else
            {
                py++;
                printf(" %d %d", px, py);
            }
        }
        else
        {
            if(py-1<1)
            {
                dir=0;
                px++;
                printf(" %d %d", px, py);
            }
            else
            {
                py--;
                printf(" %d %d", px, py);
            }
        }
        printf("\n");
    }

    int coun;
    if(dir==0)
    {
        coun=(n-px)*m+(m-py);
        printf("%d", coun);
        while(coun--)
        {
            if(dir==0)
            {
                if(py+1>m)
                {
                    dir=1;
                    px++;
                    printf(" %d %d", px, py);
                }
                else
                {
                    py++;
                    printf(" %d %d", px, py);
                }
            }
            else
            {
                if(py-1<1)
                {
                    dir=0;
                    px++;
                    printf(" %d %d", px, py);
                }
                else
                {
                    py--;
                    printf(" %d %d", px, py);
                }
            }
        }
    }
    else
    {
        coun=(n-px)*m+(py-1);
        printf("%d", coun);
        while(coun--)
        {
            if(dir==0)
            {
                if(py+1>m)
                {
                    dir=1;
                    px++;
                    printf(" %d %d", px, py);
                }
                else
                {
                    py++;
                    printf(" %d %d", px, py);
                }
            }
            else
            {
                if(py-1<1)
                {
                    dir=0;
                    px++;
                    printf(" %d %d", px, py);
                }
                else
                {
                    py--;
                    printf(" %d %d", px, py);
                }
            }
        }
    }




    return 0;
}
