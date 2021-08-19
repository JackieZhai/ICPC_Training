/*
º”¡∑Ã‚£∫Max Sum_HDU 1003
	
*/
#include <cstdio>
#include <iostream>
using namespace std;
const int MAX=100005;
int main()
{
    int t,n,a[MAX],i;
    int T=0;
    while(scanf("%d",&t)!=-1)
      while(t--)
      {
          T++;
          scanf("%d",&n);
          int sum,max,head,tail,x;
          for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
          head=tail=x=1;
          max=sum=a[1];
          for(i=2;i<=n;i++)
          {
              if(sum+a[i]<a[i])
              {
                  x=i;
                  sum=a[i];
              }
              else
              {
                  sum+=a[i];
              }
              if(sum>max)
              {
                  max=sum;
                  tail=i;
                  head=x;
              }

          }
          printf("Case %d:\n%d %d %d\n",T,max,head,tail);
          if(t) printf("\n");
      }
      return 0;
}

