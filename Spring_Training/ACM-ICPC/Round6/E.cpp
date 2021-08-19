#include <bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    int n;
    friend bool operator < (const Node &a, const Node &b)
    {
        return a.n<b.n;
    }
};
set<Node> num;
int n, m;

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        if(n==0 && m==0)
            break;
        num.clear();
        getchar();
        char buf[3];
        for(int i=0; i<m; i++)
        {
            scanf("%s", buf);

        }




    }

    return 0;
}
