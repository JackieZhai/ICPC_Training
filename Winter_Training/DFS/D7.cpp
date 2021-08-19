#include<iostream>  
#include<string.h>  
#include<stdio.h>  
#define N 25 
using namespace std;  
int n,m;  
int xmin=11;   
int map[N][N]={0};  
int dis[N][N]={0};  
int move1[4][2]={{0,-1},{0,1},{-1,0},{1,0}};  
struct point  
{  
    int x;  
    int y;  
};  
point sta,end1;  
  
point find(int k,point t)//找到并返回k方向上的墙的位置   
{  
    if(map[t.x-move1[k][0]][t.y-move1[k][1]]==1)  
    {  
        point s;  
        s.x=-1;s.y=-1;  
        return s;  
    }  
    if(k==0)  
    {  
        for(int i=0;;i++)  
        {  
            if(t.y+i>n)  
            {  
                point s;  
                s.x=-1;s.y=-1;  
                return s;  
            }  
            if(map[t.x][t.y+i]==1||map[t.x][t.y+i]==3)  
            {  
                point s;  
                s.x=t.x;  
                s.y=t.y+i;  
                return s;  
            }  
        }  
    }  
    if(k==1)  
    {  
        for(int i=0;;i++)  
        {  
            if(t.y-i<=0)  
            {  
                point s;  
                s.x=-1;s.y=-1;  
                return s;  
            }  
            if(map[t.x][t.y-i]==1||map[t.x][t.y-i]==3)  
            {  
                point s;  
                s.x=t.x;  
                s.y=t.y-i;  
                return s;  
            }  
        }  
    }  
    if(k==2)  
    {  
        for(int i=0;;i++)  
        {  
            if(t.x+i>m)  
            {  
                point s;  
                s.x=-1;s.y=-1;  
                return s;  
            }  
            if(map[t.x+i][t.y]==1||map[t.x+i][t.y]==3)  
            {  
                point s;  
                s.x=t.x+i;  
                s.y=t.y;  
                return s;  
            }  
        }  
    }  
    if(k==3)  
    {  
        for(int i=0;;i++)  
        {  
            if(t.x-i<=0)  
            {  
                point s;  
                s.x=-1;s.y=-1;  
                return s;  
            }  
            if(map[t.x-i][t.y]==1||map[t.x-i][t.y]==3)  
            {  
                point s;  
                s.x=t.x-i;  
                s.y=t.y;  
                return s;  
            }  
        }  
    }  
}  
void dfs(int n,point t)//第n步位于点t上   
{  
    if(n>=xmin)  
    {  
        return;  
    }  
    for(int i=0;i<4;i++)  
    {  
        point next;  
        next=find(i,t);  
        if(next.x==-1&&next.y==-1)  
        {  
            continue;  
        }  
        if(next.x==end1.x&&next.y==end1.y)  
        {  
            xmin=n+1;  
            return;  
        }  
        map[next.x][next.y]=0;  
        next.x=next.x+move1[i][0];  
        next.y=next.y+move1[i][1];  
        dfs(n+1,next);  
        next.x=next.x-move1[i][0];  
        next.y=next.y-move1[i][1];  
        map[next.x][next.y]=1;  
    }  
}  
  
  
  
int main()  
{  
    while(cin>>n>>m)//n列m行   
    {  
        if(n==0&&m==0)break;  
        memset(map,0,sizeof(map));  
        xmin=11;  
        for(int i=1;i<=m;i++)  
        {  
            for(int j=1;j<=n;j++)  
            {  
                scanf("%d",&map[i][j]);  
                if(map[i][j]==2)  
                {  
                    sta.x=i;  
                    sta.y=j;  
                }  
                if(map[i][j]==3)  
                {  
                    end1.x=i;  
                    end1.y=j;  
                }  
            }  
        }  
        dfs(0,sta);  
        if(xmin>=11)  
        {  
            cout<<"-1"<<endl;  
        }  
        else cout<<xmin<<endl;  
    }  
}   
