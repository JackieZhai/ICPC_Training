/*
º”¡∑Ã‚£∫Ignatius and the Princess IV_HDU 1029
	
*/
#include<iostream>
#include<string.h>
using namespace std;


int main()
{
    int n,i;
    int t;
    int cnt;
    int result;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            
            if(cnt==0)
                {
                    cnt=1;
                    result=t;
                }
            else
                {
                    if(t==result)cnt++;
                    else cnt--;
                }        
                
        }
        printf("%d\n",result);    
    }  
    return 0;  
}
