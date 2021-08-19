
///注意：树的直径指的是边的数量，不是节点的数量

bfs(1);
int Md=-1, Mn;
for(int i=0; i<V; i++)
{
    if(Md<dis[i])
    {
        Md=dis[i];
        Mn=i;
    }
}
bfs(Mn);
int L=-1;
for(int i=0; i<V; i++)
{
    if(L<dis[i])
        L=dis[i];
}
