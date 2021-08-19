#include <bits/stdc++.h>
using namespace std;

int a[1007];
int n;

int main()
{
    int pos=-2;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int cm;
    scanf("%d", &cm);
    for(int i=0; i<n; i++)
        if(a[i]==cm)
        {
            pos=i;
            break;
        }
    printf("%d\n", pos+1);

    return 0;
}
