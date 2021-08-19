#include <bits/stdc++.h>
using namespace std;


int c[37][37];
int n;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        c[i][0]=1;
        c[i][i]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j!=0)
                printf(" ");
            printf("%d", c[i][j]);
        }
        printf("\n");
    }


    return 0;
}
