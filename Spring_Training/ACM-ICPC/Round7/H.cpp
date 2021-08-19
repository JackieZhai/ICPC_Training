#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

const int Max=100007;

struct Node
{
    int l,r;
    int amax, lmaxm, rmax;    //amax������¼�������������Ĵ����ĸ�����lmax������¼������Ǹ�����������������ĸ�����rmax������¼���ұ��Ǹ�����������������ĸ���
}node[Max*4];
int a[Max];

void build(int u, int l, int r)
{
    node[u].l=l;
    node[u].r=r;
    if(l==r)
    {
        node[u].amax=node[u].lmaxm=node[u].rmax=1;
        return;
    }
    int mid=(l+r)/2;
    build(u*2, l, mid);
    build(u*2+1, mid+1, r);
    int tem;
    if(a[node[u*2].r]==a[node[u*2+1].l])
    {
        tem=node[u*2].rmax + node[u*2+1].lmaxm;
    }
    else
    {
        tem=0;
    }
    node[u].amax=max(max(node[u*2].amax,node[u*2+1].amax),tem);
    node[u].lmaxm=node[u*2].lmaxm; //�����������ߵ��Ǹ��������������Ǹ���ֵ��ͬ��
    if(node[u*2].lmaxm==mid-l+1&&a[node[u*2].r]==a[node[u*2+1].l]) //�ж���������������Ƿ���ͬ���Һ���������������Ǹ�����ͬ����ͬ�������lmax��Ҫ�仯
    {
        node[u].lmaxm+=node[u*2+1].lmaxm;
    }
    node[u].rmax=node[u*2+1].rmax; //����������ұߵ��Ǹ��������������Ǹ���ֵ��ͬ��

    if(node[u*2+1].rmax==r-mid&&a[node[u*2].r]==a[node[u*2+1].l]) //�ж���������������Ƿ���ͬ���Һ������������ұ��Ǹ�����ͬ����ͬ�������rmax��Ҫ�仯
    {
        node[u].rmax+=node[u*2].rmax;
    }
}

int query(int u, int l, int r)
{
    if(node[u].l==l&&node[u].r==r)
    {
        return node[u].amax;
    }
    int mid=(node[u].l+node[u].r)/2;
    if(r<=mid)
        return query(u*2, l, r);
    else if(l>mid)
        return query(u*2+1, l, r);
    else
    {
        int a1=query(u*2, l, mid);
        int a2=query(u*2+1, mid+1, r);
        int a3=0;
        if(a[node[u*2].r]==a[node[u*2+1].l]) //�Ƚ�
        {
            a3=min(node[u*2].rmax,mid-l+1) + min(node[u*2+1].lmaxm,r-mid);
        }
        return max(max(a1,a2),a3);
    }
}

int main()
{
    int n, p, x, y;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        scanf("%d", &p);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        build(1,1,n);
        for(int i=0; i<p; i++)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", query(1, x, y));
        }
    }

    return 0;
}
