/*
加练题：The Cow Lexicon_POJ 3267
	dp[i]表示前i个字符中剔除的最少字符数。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[1000];
char word[1000][30];
int dp[1000];

int main(){
    int n,len,k,pos,tmp;
    
    scanf("%d%d", &n, &len); 
    scanf("%s", str);
    for(int i=0; i<n; i++)
	{
        scanf("%s", word[i]);
    }
    
    dp[0]=0;    //前i个字符中包含的非法字符数量
    for(int i=1; i<=len; i++)
	{
        dp[i]=dp[i-1]+1;
        for(int j=0; j<n; j++)
		{
            tmp=k=strlen(word[j]); //单词的长度 
            k-=1;
            pos=i-1;
            while(pos>=0&&k>=0)
			{
                if(str[pos]==word[j][k])
				{
                    k--;
                }
                pos--;
            }
            if(k<0)
			{      //可以匹配出一个单词
                dp[i]=min(dp[i],dp[pos+1]+i-pos-1-tmp);
            }
        }
    }
    printf("%d\n",dp[len]);

    return 0;
}

