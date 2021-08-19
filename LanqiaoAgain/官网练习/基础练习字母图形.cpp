#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[26][26];



int main()
{
    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++)
    {
        int p=0;
        for(int j=i; j<m; j++)
        {
            a[i][j]=p++;
        }
        p=0;
        for(int j=i; j>=0; j--)
        {
            a[i][j]=p++;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%c", a[i][j]+'A');
        }
        printf("\n");
    }



    return 0;
}
