#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 256, MAX_M = 2007;  
int cost[MAX_N];  
int dp[MAX_M][MAX_M]; 
int n,m;  
string a;
  
int main()
{  
    scanf("%d%d",&n,&m);
    cin>>a;
    for(int i=0; i<n; i++)  
    {  
    	char c;
		int x,y;
        getchar();
		c=getchar();
		scanf("%d%d", &x, &y);  
        cost[c]=min(x,y);  
    } 
	
    memset(dp,0,sizeof(dp)); 
    
    for(int k=1; k<a.size(); k++)  
    {  
        for(int i=0,j=k; j<a.size(); i++,j++)  
        {
            dp[i][j]=0x3f3f3f3f;  
            if(a[i]==a[j])  
                dp[i][j]=dp[i+1][j-1];  
            else  
            {  
                dp[i][j]=min(dp[i+1][j] + cost[a[i]],dp[i][j]);  
                dp[i][j]=min(dp[i][j-1] + cost[a[j]],dp[i][j]);  
            }  
        }  
    }
    
    printf("%d\n",dp[0][a.size()-1]);  
        
    
    return 0;  
}  
