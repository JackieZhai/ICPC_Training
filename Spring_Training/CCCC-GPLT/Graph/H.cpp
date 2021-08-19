///注意此题是：反向的拓扑排序、先出大的优先队列、再逆序输出

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;


/************************类声明************************/
class Graph
{
    int V;             // 顶点个数
    list<int> *adj;    // 邻接表
    priority_queue<int> q;      // 维护一个入度为0的顶点的集合
    int* indegree;     // 记录每个顶点的入度
public:
    Graph(int V);                   // 构造函数
    ~Graph();                       // 析构函数
    void addEdge(int v, int w);     // 添加边
    bool topological_sort();        // 拓扑排序
};

/************************类定义************************/
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    indegree = new int[V];  // 入度全部初始化为0
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
            q.push(i);         // 将所有入度为0的顶点入队

    int count = 0;             // 计数，记录当前已经输出的顶点数
    while(!q.empty())
    {
        int v = q.top();      // 从队列中取出一个顶点
        q.pop();

        ++count;
        // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
        list<int>::iterator beg = adj[v].begin();
        for( ; beg!=adj[v].end(); ++beg)
            if(!(--indegree[*beg]))
                q.push(*beg);   // 若入度为0，则入栈

        ans.push_back(v+1);// 输出该顶点
    }

    if(count < V)
        return false;           // 没有输出全部顶点，有向图中有回路
    else
        return true;            // 拓扑排序成功
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        Graph g(n);   // 创建图
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
