#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

vector<int> a;
int t[3000];

int n, k;

int main()
{
    scanf("%d%d", &n, &k);

    for(int i=0; i<3000; i++)
        t[i]=0;

    for(int i=0; i<k; i++)
    {
        int buf;
        buf-=n;
        scanf("%d", &buf);
        a.push_back(buf);
    }

    queue<int> que;
    que.push(0);
    while(que.size())
    {
        int q=que.front();
        que.pop();

        for(int i=0; i<a.size(); i++)
        {
            int sum=q+a[i];

            t[q+1500]++;
            if(q==0)
            {
                printf("%d\n", t[q+1500]);
                return 0;
            }
            que.push(sum);
        }


    }



    return 0;
}
