#include <bits/stdc++.h>
using namespace std;

bool used[107];
int a[107];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int n;
	scanf("%d", &n);
    fill(used, used+n+1, false);

    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);

    int ans=1;
    for(int i=1; i<=n; i++)
    {
        if(used[i])
            continue;
        used[i]=true;
        int aa=a[i];

        int coun=1;
        while(aa!=i)
        {
            used[aa]=true;
            aa=a[aa];
            coun++;
            if(coun>n)
            {
                printf("-1\n");
                return 0;
            }
        }
        if(coun%2==0)
            coun/=2;
        ans=ans*coun/gcd(ans,coun);
    }
    printf("%d\n",ans);



	return 0;
}
