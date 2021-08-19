#include <cstdio>
#include <algorithm>
using namespace std;
int a[55]={0};
int main()
{
    int i,j,k,n,m,max1=-100;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        max1=-100;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[j]);
        }
        sort(a,a+m);
        for(j=0;j<m-1;j++)
        {
            if(a[j+1]-a[j]>max1)
                max1=a[j+1]-a[j];
        }

        printf("Class %d\n",i+1);
        printf("Max %d, Min %d, Largest gap %d\n",a[m-1],a[0],max1);



    }
    return 0;
}
