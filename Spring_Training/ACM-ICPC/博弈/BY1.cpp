/**
例题：Cutting Game_POJ 2311
    计算分割问题的Grundy值
*/
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_WH=207;

//记忆化搜索所用的数组，程序开始时初始化为-1
int mem[MAX_WH][MAX_WH];

int grundy(int w, int h)
{
    if(mem[w][h]!=-1)
        return mem[w][h];

    set<int> s;
    //切割纸张时，总要保证长和宽至少为2
    for(int i=2; w-i>=2; i++)
        s.insert(grundy(i, h)^grundy(w-i, h));
    for(int i=2; h-i>=2; i++)
        s.insert(grundy(w, i)^grundy(w, h-i));

    int res=0;
    while(s.count(res))
        res++;

    return mem[w][h]=res;
}

int main()
{
    //初始化
    for(int i=0; i<MAX_WH; i++)
        for(int j=0; j<MAX_WH; j++)
            mem[i][j]=-1;

    int w, h;
    while(scanf("%d%d", &w, &h)!=EOF)
    {
        if(grundy(w, h)!=0)
            puts("WIN");
        else
            puts("LOSE");
    }


    return 0;
}
