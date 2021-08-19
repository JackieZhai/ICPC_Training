/*
练习题：Meteor Shower_POJ3669 
*/
#include <cstdio>
#include <cstring>  
#include <queue>  
using namespace std;  

//存放所有陨石数据，永远没有陨石的地方用-1代替 
int map[310][310];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};  
//去过的地方置1，避免重复走 
int mark[310][310];  
struct node  
{  
    int x,y,step;  
}temp,a;
//使得priority_queue变为从小到大排列的优先队列 
bool operator < (const node &a,const node &b)  
{  
    return a.step>b.step;  
}   

int min(int a,int b)  
{  
    return a>b?b:a;  
}  

void bfs()  
{  
    int i;  
    memset(mark,0,sizeof(mark));  
    priority_queue<node>q;  
    a.x=0;  
    a.y=0;  
    a.step=0;  
    q.push(a);  
    mark[0][0]=1;  
    while(q.size())  
    {
    	//取出的第一个到达(map[][]=-1)的一定是用step数最少的
		//运用priority_queue还能有效的节省时间，防止TLE 
        a=q.top();  
        q.pop();  
        if(map[a.x][a.y]==-1)  
        {
            printf("%d\n",a.step);  
            return ;  
        }
        for(i=0;i<4;++i)  
        {  
            temp.x=a.x+dir[i][0];  
            temp.y=a.y+dir[i][1];  
            temp.step=a.step+1;  
            if(temp.x>=0&&temp.y>=0&&(map[temp.x][temp.y]==-1||map[temp.x][temp.y]>temp.step))  
            {  
                if(mark[temp.x][temp.y]==0)  
                	q.push(temp);
                mark[temp.x][temp.y]=1;
            }  
        }  
    }  
    printf("-1\n");  
}  
  
  
  
int main()  
{  
    int n,x,y,t,i,j;  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(map,-1,sizeof(map));  
        for(i=0;i<n;++i)  
        {  
            scanf("%d%d%d",&x,&y,&t);  
            if(map[x][y]==-1)//判断是否更新撞击时间  
                map[x][y]=t;  
            else  
                map[x][y]=min(map[x][y],t);//受过撞击的地方不可以再走了 
            for(j=0;j<4;++j)  
            {  
                int nx=x+dir[j][0];  
                int ny=y+dir[j][1];  
                if(nx>=0&&ny>=0)  
                {  
                    if(map[nx][ny]==-1)  
                        map[nx][ny]=t;  
                    else  
                        map[nx][ny]=min(t,map[nx][ny]);   
                }  
            }  
        }  
        bfs();  
    }  
    return 0;  
}   
