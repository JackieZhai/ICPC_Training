#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

///用两个priority_queue貌似不对
typedef pair<int, int> P;
//first=P, second=K

set<P> se;
set<P>::iterator it;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        else if(n==1)
        {
            int k, p;
            scanf("%d%d", &k, &p);
            se.insert(P(p, k));
        }
        else if(n==2)
        {
            if(se.size()==0)
            {
                printf("0\n");
                continue;
            }

            it=se.end();
            it--;
            printf("%d\n", (*it).second);
            se.erase(it);
        }
        else
        {
            if(se.size()==0)
            {
                printf("0\n");
                continue;
            }

            it=se.begin();
            printf("%d\n", (*it).second);
            se.erase(it);
        }
    }



    return 0;
}
