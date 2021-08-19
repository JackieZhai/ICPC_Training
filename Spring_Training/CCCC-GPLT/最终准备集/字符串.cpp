///�ַ������

///ƥ��
char str[]="1234xyz";
char *str1=strstr(str,"34");
cout << str1 << endl;


/*
���������������(LCS)��
	ע������������У��������������У�����ֻҪ�����˳��ȡ�
	���Ӷȣ�O(s.size() X t.size())
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
�����������(LIS, Longest Increasing Subsequence)���⣺
	solve1()������dp[i]Ϊ��aiΪĩβ������������еĳ��ȣ�O(n^2)��
	solve2()������dp[i]Ϊ����Ϊi+1��������������ĩβԪ�ص���Сֵ��
		����֪������dp[]����INF֮���ǵ��������ģ��������ö��������õ������O(nlogn)��
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
	fill(dp, dp+n, INF); //INF ��Ϊ -1 ��ΪLDS
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp, dp+n, a[i]) = a[i]; //, greater<int>() ��ΪLDS; ��Ϊupper�������½���
	}
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp); //, greater<int>(); INF ��Ϊ -1 ��ΪLDS
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
���������������(LCS)��
	���LCS
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
            else i++;    //��ƽ��
            j--;    //��Сһ����ģ
        }
        i--;    //��ƽ��
    }

    printf("%s\n", ans);
    return 0;
}


/*
������Ӵ���
    Manacher�㷨
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

    s_new[j] = '\0';  //������Ŷ

    return j;  //����s_new�ĳ���
}

int Manacher()
{
    int len = Init();  //ȡ�����ַ������Ȳ������s_new��ת��
    int maxLen = -1;   //����ĳ���

    int id;
    int mx = 0;

    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  //����߽��жϣ���Ϊ����'$',����'\0'
            p[i]++;


        if (mx < i + p[i])  //����ÿ��һ��i����Ҫ��mx�Ƚϣ�����ϣ��mx�����ܵ�Զ���������ܸ��л���ִ��if (i < mx)�����룬�Ӷ����Ч��
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
    while (printf("�������ַ�����\n"))
    {
        scanf("%s", s);
        printf("����ĳ���Ϊ %d\n\n", Manacher());
    }

    return 0;
}
