//�������������в������һ������
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
