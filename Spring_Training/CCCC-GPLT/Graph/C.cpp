#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define RD(x) scanf("%d",&x)
#define REP(i,n) for(i=0;i<n;i++)
const int MAXN=222;
const int g[2][4]= {{0,0,1,-1},{-1,1,0,0}};
const double eps=1e-5;
int n,m;
int a[MAXN][MAXN];
int p[2][2];
bool visited[MAXN][MAXN];
int seeChecked[MAXN][MAXN];
bool ok(int now[2], int next[2]) {
    int y=next[1], x=next[0];
    int h1=a[now[0]][now[1]];
    int h2=a[next[0]][next[1]];
    if(x<0 || y<0 || x>=n || y>=m)return false;
    if(h2-h1>1 || h1-h2>3)return false;
    return true;
}

bool canSee2Dot(int x1,int y1,int x2,int y2) {
    bool re=true;
    int k;
    int p[2][2];
    p[0][0]=x1;
    p[0][1]=y1;
    p[1][0]=x2;
    p[1][1]=y2;
//    printf("(%d,%d)->(%d,%d)\n",x1,y1,x2,y2);
    REP(k,2) {
        int st0=p[0][k],ed0=p[1][k];
        int st1=p[0][k^1], ed1= p[1][k^1];
        if(st0==ed0)continue;
        if(ed0<st0) {
            swap(ed0,st0);
            swap(ed1,st1);
        }
//        printf("k=%d,%d->%d\n",k,st0,ed0);
        double kk=ed1-st1;
        kk/=ed0-st0;
        double hk=a[ed0][ed1] - a[st0][st1];
        if(k==1)hk=a[ed1][ed0]-a[st1][st0];
        hk/=ed0-st0;
        double now = st1 + 0.5 + 0.5*kk;
        double nowh = a[st0][st1] + 0.5 + 0.5 * hk;
        if(k==1)nowh = a[st1][st0] + 0.5 + 0.5*hk;
//        printf("%d,%d,%f,%f\n",st0,st1,hk,nowh);
        for(int i=st0; i<ed0; i++) {
            int theNow = floor(now);
            int theX,theY;
            double theH1,theH2;
            if(fabs(now-round(now))>eps) {
                if(k==0) {
                    theX=i;
                    theY=theNow;
                    theH1=a[theX][theY];
                    theH2=a[theX+1][theY];
                } else {
                    theX=theNow;
                    theY=i;
                    theH1=a[theX][theY];
                    theH2=a[theX][theY+1];
                }
//                printf("%d,%d,%f,%f,%f,(%f)\n",theX,theY,theH1,theH2,nowh,now);

            } else {
                if(k==0) {
                    theX=i;
                    theY=floor(now-0.5*fabs(kk)/kk);
                    theH1=a[theX][theY];
                    theH2=a[theX+1][(int)floor(now+0.5*fabs(kk)/kk)];
                } else {
                    theX=floor(now-0.5*fabs(kk)/kk);
                    theY=i;
                    theH1=a[theX][theY];
                    theH2=a[(int)floor(now+0.5*fabs(kk)/kk)][theY+1];
                }
//                printf("%d,%d,%f,%f,%f,(%f)\n",theX,theY,theH1,theH2,nowh,now);
            }
            if(theH1>nowh || theH2>nowh) {
                re=false;
                break;
            }
            now+=kk;
            nowh+=hk;
        }
        if(!re)break;
    }
    return re;
}

bool canSee(int d[2]) {
    int x=d[0], y=d[1];
    if(seeChecked[x][y]!=-1)return seeChecked[x][y];
    bool re=canSee2Dot(x,y,p[0][0],p[0][1]) || canSee2Dot(x,y,p[1][0],p[1][1]);
    seeChecked[x][y]=re;
    return re;
}
int farm() {
    int b[MAXN*MAXN][3];
    int bl=0,br=1;
    int i;
    if(p[0][0]==p[1][0] && p[0][1]==p[1][1])return 0;
    memset(visited,0,sizeof(visited));
    memset(seeChecked,-1,sizeof(seeChecked));
    b[0][0]=p[0][0];
    b[0][1]=p[0][1];
    while(bl<br) {
        int now[3];
        now[0]=b[bl][0];
        now[1]=b[bl][1];
        now[2]=b[bl][2];
//        printf("now(%d,%d)\n", now[0],now[1]);
        bl++;
        REP(i,4) {
            int next[3];
            next[0] = now[0]+g[0][i];
            next[1] = now[1]+g[1][i];
            next[2] = now[2]+1;
            if(!visited[next[0]][next[1]] && ok(now,next) && canSee(next)) {
                if(next[0]==p[1][0] && next[1]==p[1][1])return next[2];
                b[br][0]=next[0];
                b[br][1]=next[1];
                b[br][2]=next[2];
                br++;
                visited[next[0]][next[1]]=true;
            }
        }
    }
    return -1;
}

int main() {
    int T,i,j;
    int x;
    RD(T);
    while(T--) {
        scanf("%d%d",&n,&m);
        REP(i,n)REP(j,m)RD(a[i][j]);
        scanf("%d%d%d%d",&p[0][0],&p[0][1], &p[1][0], &p[1][1]);
        p[0][0]--;
        p[0][1]--;
        p[1][0]--;
        p[1][1]--;
        x = farm();
        if(x!=-1)
            printf("The shortest path is %d steps long.",x);
        else
            printf("Mission impossible!");
    }
    return 0;
}
