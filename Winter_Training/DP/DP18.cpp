/*
�����⣺The Cow Lexicon_POJ 3267
	dp[i]��ʾǰi���ַ����޳��������ַ����� 
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
    
    dp[0]=0;    //ǰi���ַ��а����ķǷ��ַ�����
    for(int i=1; i<=len; i++)
	{
        dp[i]=dp[i-1]+1;
        for(int j=0; j<n; j++)
		{
            tmp=k=strlen(word[j]); //���ʵĳ��� 
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
			{      //����ƥ���һ������
                dp[i]=min(dp[i],dp[pos+1]+i-pos-1-tmp);
            }
        }
    }
    printf("%d\n",dp[len]);

    return 0;
}

