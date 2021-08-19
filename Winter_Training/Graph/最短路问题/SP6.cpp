/*
��ϰ�⣺Six Degrees of Cowvin Bacon_POJ 2139
���õ���Dijkstra�㷨����ʵFloyd�㷨������(��Ҫ��V��300)�� 
*/


 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V=307;
const int INF=1000000009;

struct edge {
	int to, cost;
};
typedef pair<int, int> P;//����first��ʾ��̾��룬second��ʾ����ı�� 

int V, M;
vector<edge> G[MAX_V]; //�±�䵱from
int d[MAX_V];
float mean[MAX_V];
int a[MAX_V];

void dijkstra(int s)
{
	//����first��С����˳�����У���ȡ����̾���Ͷ�Ӧ�Ķ��� 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(que.size()) //���Ӷ�ΪO(|E|Xlog|V|) 
	{
		P p = que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0; i<G[v].size(); i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}


int main()
{
	scanf("%d%d", &V, &M);
	for(int i=0; i<M; i++)
	{
		int n;
		scanf("%d", &n);
		for(int j=0; j<n; j++)
		{  
            scanf("%d",&a[j]); 
        }  
        for(int j=0; j<n; j++)
		{  
            for(int k=j+1; k<n; k++)
			{
				edge e1,e2;
				e1.to=a[k]-1;
				e1.cost=1;
				e2.to=a[j]-1;
				e2.cost=1;
				G[a[j]-1].push_back(e1);
				G[a[k]-1].push_back(e2);
            }  
        } 
		
	
	}
	
	for(int i=0; i<V; i++)
	{
		int count=0;
		dijkstra(i);
		for(int j=0; j<V; j++)
		{
			if(i!=j)
			{
				mean[i]+=d[j];
				count++;
			}
		}
		mean[i]/=count;
	}
	
	float ans=INF;
	for(int i=0; i<V; i++)
	{
		if(ans>mean[i]&&mean[i]!=0)
			ans=mean[i];
	}
	printf("%d\n", int(ans*100));
	
	return 0;
}




/*
#include <cstdio>  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <cstring>
using namespace std;  
  
const int INF=1000000009;  
int dis[605][605];  
int a[605];  
int n;  
  
void floyd(){  
    for(int i=1;i<=n;i++){  
        for(int j=1;j<=n;j++){  
            for(int k=1;k<=n;k++){  
                    dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);  
            }  
        }  
    }  
}  
  
int main(){  
    int m;  
    scanf("%d%d",&n,&m);  
    memset(dis,INF,sizeof(dis));  
    for(int i=0;i<m;i++){  
        int nn;  
        scanf("%d",&nn);  
        for(int j=0;j<nn;j++){  
            scanf("%d",&a[j]);  
        }  
        for(int j=0;j<nn;j++){  
            for(int k=0;k<j;k++){  
                dis[a[j]][a[k]]=dis[a[k]][a[j]]=1;  
            }  
        }  
    }  
    floyd();  
    int ans=INF;  
    for(int i=1;i<=n;i++){  
        int sum=0;  
        for(int j=1;j<=n;j++){  
            if(i!=j)  
                sum+=dis[i][j];  
        }  
        ans=min(sum,ans);  
    }  
    printf("%d\n",int(ans*100/(n-1)));  
    return 0;  
}  
*/

























