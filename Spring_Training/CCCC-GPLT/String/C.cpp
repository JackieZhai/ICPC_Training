#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[15][65];
char sub[65];
char ans[65];
int len;

int main()
{
    int t,i,j,k,n,maxn;
    scanf("%d",&t);
    while(t--)
    {
        maxn = 0;
        scanf("%d",&n);
        memset(ans,'\0',sizeof(ans));
        for(i = 1; i<=n; i++)
            scanf("%s",str[i]);
        for(i = 1; i<=60; i++)
        {
            int find = 0;
            for(j = 0; j<=60-i; j++)
            {   //枚举每一种子串 
                len = 0;
                int check = 1;
                for(k = j;;k++)
                {
                    sub[len++] = str[1][k];
                    if(len == i)
                        break;
                }
                sub[len] = '\0';
                for(k = 2; k<=n; k++)
                {
                    if(!strstr(str[k],sub))
                    {
                        check = 0;
                        break;
                    }
                }
                if(check)
                {
                    find = 1;
                    if(strlen(ans)<strlen(sub))
                    	strcpy(ans,sub);
                    else if(strcmp(ans,sub)>0)
                    	strcpy(ans,sub);
                }
            }
            if(!find)
            break;
        }
        if(strlen(ans)<3)
            printf("no significant commonalities\n");
        else
            printf("%s\n",ans);
    }

    return 0;
}


