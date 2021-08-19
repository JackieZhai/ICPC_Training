#include <cstdio>
#include <iostream>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    for(int kase=1; kase<=n; kase++)
    {
        printf("Scenario #%d:\n", kase);

        int l, r;
        scanf("%d%d", &l, &r);
        int a=0, b=0;
        while(l!=0 || r!=0)
        {
            if(l==0)
            {
                a--;
                break;
            }
            else if(r==0)
            {
                b--;
                break;
            }
            if(l>r)
            {
                int c=l/r;
                l-=r*c;
                a+=c;
            }
            else
            {
                int c=r/l;
                r-=l*c;
                b+=c;
            }
        }

        printf("%d %d\n", a, b);

        if(kase!=n)
            printf("\n");
    }




    return 0;
}
