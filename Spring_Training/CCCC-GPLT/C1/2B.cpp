#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100000+10;
struct Node{
    int nextad;
    int key;
}nod[maxn];
int start_ad, n;
bool vis[10010];

void _output(int p) {
    while(p != -1) {
        printf("%05d %d ", p, nod[p].key);
        if(-1 == nod[p].nextad) {
            printf("-1\n");
        }else {
            printf("%05d\n", nod[p].nextad);
        }
        p = nod[p].nextad;
    }
}

int main() {
    while(~scanf("%d%d", &start_ad, &n)) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            int p,q,r;
            scanf("%d%d%d", &p, &q, &r);
            nod[p].key = q;
            nod[p].nextad = r;
        }
        int pre = start_ad, next = start_ad;
        int begin_ad = -1, pre2;
        vis[abs(nod[start_ad].key)] = true;
        for(int i = 1; i < n; i++) {
            next = nod[pre].nextad;
            if(vis[abs(nod[next].key)]) {
                if(-1 == nod[next].nextad) {//删除最后一个节点 
                    nod[pre].nextad = -1;
                }else {
                    nod[pre].nextad = nod[next].nextad;
                }
                //刚删除的节点的后继一定赋值为-1
                nod[next].nextad = -1;
                if(-1 == begin_ad) {//第一次删除节点 
                    begin_ad = next;
                    pre2 = begin_ad;
                }else {
                    nod[pre2].nextad = next;
                    pre2 = next;
                }
            }else {
                pre = next;
                vis[abs(nod[pre].key)] = true;
            }
        }
        _output(start_ad);
        _output(begin_ad);
    }
    return 0;
}
