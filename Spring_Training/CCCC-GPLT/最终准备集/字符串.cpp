///字符串相关

///匹配
char str[]="1234xyz";
char *str1=strstr(str,"34");
cout << str1 << endl;


/*
最长公共子序列问题(LCS)：
	注：求的是子数列，不是连续子数列；而且只要求求了长度。
	复杂度：O(s.size() X t.size())
*/
#include <bits/stdc++.h>
using namespace std;

string s, t;

int dp[1007][1007];

void solve()
{
	for(int i=0; i<s.size(); i++)
		for(int j=0; j<t.size(); j++)
			if(s[i]==t[j])
				dp[i+1][j+1]=dp[i][j]+1;
			else
				dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);

	printf("%d\n", dp[s.size()][t.size()]);

}

int main()
{
	getline(cin, s);
	getline(cin, t);

	solve();

	return 0;

}


/*
最长上升子序列(LIS, Longest Increasing Subsequence)问题：
	solve1()：定义dp[i]为以ai为末尾的最长上升子数列的长度，O(n^2)；
	solve2()：定义dp[i]为长度为i+1的上升子数列中末尾元素的最小值；
		由于知道这种dp[]除了INF之外是单调递增的，可以利用二分搜索得到更快的O(nlogn)。
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1007, INF=0x3f3f3f3f;

int n;
int a[MAX_N];

int dp[MAX_N];

void solve1()
{
	int res=0;
	for(int i=0; i<n; i++)
	{
		dp[i]=1;
		for(int j=0; j<i; j++)
		{
			if(a[j]<a[i])
				dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	printf("%d\n", res);
}

void solve2()
{
	fill(dp, dp+n, INF); //INF 改为 -1 变为LDS
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp, dp+n, a[i]) = a[i]; //, greater<int>() 变为LDS; 改为upper变成最长不下降。
	}
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp); //, greater<int>(); INF 改为 -1 变为LDS
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	//solve1();
	solve2();

	return 0;
}


/*
最长公共子序列问题(LCS)：
	输出LCS
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1001
#define max(x,y) ((x)>(y)?(x):(y))

char s1[MAX], s2[MAX];
int maxLen[MAX][MAX];
char ans[MAX];

int main()
{
    int k = 0;
    scanf("%s%s", s1,s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i-1] == s2[j-1])
                maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
            else maxLen[i][j] = max(maxLen[i][j - 1], maxLen[i-1][j]);
        }
    }

    int i = len1;
    int j = len2;
    while(i)
    {
        if (maxLen[i][j] > maxLen[i - 1][j])
        {
            if (maxLen[i][j] > maxLen[i][j - 1])
                ans[maxLen[i][j] - 1] = s1[i - 1];
            else i++;    //左平移
            j--;    //减小一个规模
        }
        i--;    //上平移
    }

    printf("%s\n", ans);
    return 0;
}


/*
最长回文子串：
    Manacher算法
*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char s[1000];
char s_new[2000];
int p[2000];

int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;

    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }

    s_new[j] = '\0';  //别忘了哦

    return j;  //返回s_new的长度
}

int Manacher()
{
    int len = Init();  //取得新字符串长度并完成向s_new的转换
    int maxLen = -1;   //最长回文长度

    int id;
    int mx = 0;

    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  //不需边界判断，因为左有'$',右有'\0'
            p[i]++;


        if (mx < i + p[i])  //我们每走一步i，都要和mx比较，我们希望mx尽可能的远，这样才能更有机会执行if (i < mx)这句代码，从而提高效率
        {
            id = i;
            mx = i + p[i];
        }

        maxLen = max(maxLen, p[i] - 1);
    }

    return maxLen;
}

int main()
{
    while (printf("请输入字符串：\n"))
    {
        scanf("%s", s);
        printf("最长回文长度为 %d\n\n", Manacher());
    }

    return 0;
}
