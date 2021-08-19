/*
	Dijkstra的深入理解 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_V=200007;
typedef long long ll;  

struct node  
{  
    int to;
	ll w;  
    node(){}  
    node(ll to,ll w)  
    {  
        this->to=to;  
        this->w=w;  
    }  
};  

vector<node> G[MAX_V];  
ll a[MAX_V],dist[MAX_V],mark[MAX_V];
int n,m;  
priority_queue<node>que;  
bool operator<(node a,node b)  
{  
    return a.w>b.w;  
}  


void dij()  
{  
    for(int i=1;i<=n;i++)  
    {
        dist[i]=a[i];
		mark[i]=0;
		que.push(node(i,dist[i]));  
	}
    while(!que.empty())  
    {  
        node k=que.top();  
        que.pop();  
        
        if(mark[k.to])
			continue;  
        mark[k.to]=1; 
        
        for(int i=0;i<G[k.to].size();i++)  
        {  
            int to=G[k.to][i].to;  
            if(mark[to]==0&&dist[to]>k.w+G[k.to][i].w)  
            {  
                dist[to]=k.w+G[k.to][i].w;  
                que.push(node(to,dist[to]));  
            }  
        }  
    }  
}  
  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for(int i=0;i<m;i++)  
    {  
        int u,v;
		ll w;  
        scanf("%d%d%I64d",&u,&v,&w);  
        G[u].push_back(node(v,w*2));  
        G[v].push_back(node(u,w*2));  
    }  
    for(int i=1;i<=n;i++)  
        scanf("%I64d",&a[i]);  
        
    dij();  
    
    for(int i=1;i<=n;i++)  
        printf("%I64d ",dist[i]);  
    printf("\n");  
}  
