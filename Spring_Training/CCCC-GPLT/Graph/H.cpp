///ע������ǣ���������������ȳ�������ȶ��С����������

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;


/************************������************************/
class Graph
{
    int V;             // �������
    list<int> *adj;    // �ڽӱ�
    priority_queue<int> q;      // ά��һ�����Ϊ0�Ķ���ļ���
    int* indegree;     // ��¼ÿ����������
public:
    Graph(int V);                   // ���캯��
    ~Graph();                       // ��������
    void addEdge(int v, int w);     // ��ӱ�
    bool topological_sort();        // ��������
};

/************************�ඨ��************************/
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    indegree = new int[V];  // ���ȫ����ʼ��Ϊ0
    for(int i=0; i<V; ++i)
        indegree[i] = 0;
}

Graph::~Graph()
{
    delete [] adj;
    delete [] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ++indegree[w];
}

bool Graph::topological_sort()
{
    for(int i=0; i<V; ++i)
        if(indegree[i] == 0)
            q.push(i);         // ���������Ϊ0�Ķ������

    int count = 0;             // ��������¼��ǰ�Ѿ�����Ķ�����
    while(!q.empty())
    {
        int v = q.top();      // �Ӷ�����ȡ��һ������
        q.pop();

        ++count;
        // ������vָ��Ķ������ȼ�1��������ȼ�Ϊ0�Ķ�����ջ
        list<int>::iterator beg = adj[v].begin();
        for( ; beg!=adj[v].end(); ++beg)
            if(!(--indegree[*beg]))
                q.push(*beg);   // �����Ϊ0������ջ

        ans.push_back(v+1);// ����ö���
    }

    if(count < V)
        return false;           // û�����ȫ�����㣬����ͼ���л�·
    else
        return true;            // ��������ɹ�
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        Graph g(n);   // ����ͼ
        while(m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            g.addEdge(b, a);
        }

        ans.clear();
        g.topological_sort();

        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size();  i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }




    return 0;
}
