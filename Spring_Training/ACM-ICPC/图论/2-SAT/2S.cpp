//������ʽΪ(av-b)^(bvc)^(-cv-a)
//�����������㣬�ֱ��Ӧa,b,c,-a,-b,-c

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V=10;

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


int main()
{
    V=6;
    add_edge(3, 4);
    add_edge(1, 0);
    add_edge(4, 2);
    add_edge(5, 1);
    add_edge(2, 3);
    add_edge(0, 5);

    scc();

    //�ж�x��-x�Ƿ��ڲ�ͬ��ǿ��ͨ������
    for(int i=0; i<3; i++)
    {
        if(cmp[i]==cmp[3+i])
        {
            printf("NO\n");
            return 0;
        }
    }

    //��������㣬����һ���
    printf("YES\n");
    for(int i=0; i<3; i++)
    {
        if(cmp[i]>cmp[3+i])
            printf("true\n");
        else
            printf("false\n");
    }



    return 0;
}
