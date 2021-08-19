/**
���⣺Popular Cows_POJ 2186

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V=10007;

int V; //������
vector<int> G[MAX_V]; //ͼ���ڽӱ�ʾ
vector<int> rG[MAX_V]; //�ѱ߷�����ͼ
vector<int> vs; //�������˳��Ķ����б�
bool used[MAX_V]; //���ʱ��
int cmp[MAX_V]; //����ǿ��ͨ������������

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
        if(!used[G[v][i]])
            dfs(G[v][i]);
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0; i<rG[v].size(); i++)
        if(!used[rG[v][i]])
            rdfs(rG[v][i], k);
}

int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v=0; v<V; v++)
        if(!used[v])
            dfs(v);
    memset(used, 0, sizeof(used));
    int k=0;
    for(int i=vs.size()-1; i>=0;  i--)
        if(!used[vs[i]])
            rdfs(vs[i], k++);
    return k; //�����м���ǿ��ͨ����
}

const int MAX_M=50007;
//����
int N, M;
int A[MAX_M], B[MAX_M];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &A[i], &B[i]);
    }
    V=N;
    for(int i=0; i<M; i++)
    {
        add_edge(A[i]-1, B[i]-1);
    }
    int n=scc();

    //�������ĸ���
    int u=0, num=0;
    for(int v=0; v<V; v++)
    {
        if(cmp[v]==n-1)
        {
            u=v;
            num++;
        }
    }

    //����ͨ
    memset(used, 0, sizeof(used));
    rdfs(u, 0); //���ô��룬k������������
    for(int v=0; v<V;  v++)
        if(!used[v])
        {
            //���ɴ�
            num=0;
            break;
        }

    printf("%d\n", num);

    return 0;
}
