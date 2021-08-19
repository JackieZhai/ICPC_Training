/*
��ϰ�⣺Meteor Shower_POJ3669 
*/
#include <cstdio>
#include <cstring>  
#include <queue>  
using namespace std;  

//���������ʯ���ݣ���Զû����ʯ�ĵط���-1���� 
int map[310][310];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};  
//ȥ���ĵط���1�������ظ��� 
int mark[310][310];  
struct node  
{  
    int x,y,step;  
}temp,a;
//ʹ��priority_queue��Ϊ��С�������е����ȶ��� 
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
    	//ȡ���ĵ�һ������(map[][]=-1)��һ������step�����ٵ�
		//����priority_queue������Ч�Ľ�ʡʱ�䣬��ֹTLE 
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
            if(map[x][y]==-1)//�ж��Ƿ����ײ��ʱ��  
                map[x][y]=t;  
            else  
                map[x][y]=min(map[x][y],t);//�ܹ�ײ���ĵط������������� 
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
