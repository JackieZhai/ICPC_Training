#include <bits/stdc++.h>
using namespace std;


const int MAX_V=;



//����
vector<int> G[MAX_V];
int root;

int vs[MAX_V*2-1]; //DFS���ʵ�˳��
int depth[MAX_V*2-1]; //�ڵ�����
int id[MAX_V]; //����������vs���״γ��ֵ��±�

void dfs(int v, int p, int d, int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0; i<G[v].size(); i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i], v, d+1, k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}

//Ԥ����
void init(int V)
{
    //Ԥ�����vs��depth��id
    int k=0;
    dfs(root, -1, 0, k);
    //Ԥ�����RMQ(���صĲ�����Сֵ��������Сֵ��Ӧ���±�)
    rmq_init(depth, V*2-1);
}

//����u��v��LCA
int lca(int u, int v)
{
    return vs[query(min(id[u], id[v]), max(id[u], id[v])+1)];
}
