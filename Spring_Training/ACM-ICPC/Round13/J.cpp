#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000000];
char s_new[2000000];
int p[2000000];

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

    s_new[j] = '\0';  // 别忘了哦

    return j;  // 返回 s_new 的长度
}

int Manacher()
{
    int len = Init();  // 取得新字符串长度并完成向 s_new 的转换
    int max_len = -1;  // 最长回文长度

    int id;
    int mx = 0;

    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);  // 需搞清楚上面那张图含义, mx 和 2*id-i 的含义
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  // 不需边界判断，因为左有'$',右有'\0'
            p[i]++;

        // 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }

        max_len = max(max_len, p[i] - 1);
    }

    return max_len;
}


int main()
{
    int kase=0;
    while(true)
    {
        kase++;
        scanf("%s", s);
        if(strcmp(s, "END")==0)
            break;
        printf("Case %d: %d\n", kase, Manacher());
    }


    return 0;
}
