#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int N = 110;

struct Node {
    int x, y;
} p[N];

int cmp(Node a, Node b) 
{
    if(a.y == b.y)
        return a.x > b.x;
    return a.y < b.y;
}

int main() 
{
    string E[N], t;
    int n, m;
    while(cin >> n >> m && n) 
	{
        for(int i = 0; i < n; i++)
            cin >> E[i];
        getchar();
        int ans = 0;
        while(m--) 
		{
            getline(cin, t);
            int lent = t.size();
            int cnt = 0;
            for(int i = 0; i < n; i++) 
			{
                int lene = E[i].size();
                int pos = 0;
                while(pos < lent && t.find(E[i], pos) != t.npos) 
				{
                    p[cnt].x = t.find(E[i], pos);
                    p[cnt].y = p[cnt].x + lene - 1;
                    pos = p[cnt].x + 1;
                    cnt ++;
                }
            }
            if(cnt == 0)
                continue;
            sort(p, p + cnt, cmp);
            ans ++;
            int temp = p[0].y;
            for(int i = 0; i < cnt; i++) 
			{
                if(p[i].x > temp) 
				{
                    ans ++;
                    temp = p[i].y;
                }
            }
        }
        cout << ans << endl;
    }
    
    
    return 0;
}
