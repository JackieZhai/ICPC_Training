/*
��ϰ�⣺Moo University - Financial Aid_POJ 2010
	����ؼ����ڽ�ģ��
����ѧ��ѧ�����ɼ��������Ǵ���Щѧ����һ��ѡ����λ������ô�ض�����λ��ǰѡ��n/2����
��λ������ѡ��n/2��ѧ������ô���ѡ����n/2��ѧ���أ��϶���ѡ�񾭼�Ԯ��֮�����ٵ�ѧ����
������ߵ�n/2��ѧ������λ��ѡ�����Ǹ�ѧ��ÿ�����ƶ�һλ����߾Ͷ��һ��ѧ����ѡ��
���ǽ�������һ��ѧ������������Ԯ���Ӵ�С���е����ȶ��У�
��ô�����ȶ��еĿ�ͷ�ض�����ҪԮ������ѧ��������pop����ÿһ�ζ���ô���¼�¼��l[i]���ɡ�
ͬ���ұߵ�n/2��ѧ��Ҳ��ôѡ�񣬰Ѻͼ�¼��r[i]����ձ���һ�����С�ڵ���f������λ�����ļ��ɡ� 
*/ 
#include<algorithm>  
#include<cmath>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<map>  
#include<queue>  
#define ll long long  
using namespace std;  
  
const int INF = 0x7f7f7f7f;  
const int MAXN = 1e5 + 111;  
  
struct C {  
    int s, f;  
    bool operator < (const C &t)const {  
        return f < t.f;  
    }  
}cow[MAXN];  
  
ll l[MAXN], r[MAXN];  
  
bool cmp(C a, C b) {  
    return a.s < b.s;  
}  
  
int main()  
{  
    int n, c, f; scanf("%d%d%d", &n, &c, &f);  
    for (int i = 0; i < c; ++i) scanf("%d%d", &cow[i].s, &cow[i].f);  
    sort(cow, cow + c, cmp);  
  
    int need = (n - 1) / 2;  
    int up = c - need; // ��λ����ȡ�������� 
  
    // ����l[i]  
    priority_queue<C, vector<C> > pq;  
    ll sum = 0;  
    for (int i = 0; i < need; ++i) {  
        pq.push(cow[i]);  
        sum += cow[i].f;  
    }  
    for (int i = need; i < up; ++i) {  
        l[i] = sum;  
        sum += cow[i].f;  
        pq.push(cow[i]);  
        sum -= pq.top().f;  
        pq.pop();  
    }  
  
    // ����r[i]  
    priority_queue<C, vector<C> > pq2;  
    sum = 0;  
    for (int i = up; i < c; ++i) {  
        pq2.push(cow[i]);  
        sum += cow[i].f;  
    }  
    for (int i = up - 1; i >= need; --i) {  
        r[i] = sum;  
        sum += cow[i].f;  
        pq2.push(cow[i]);  
        sum -= pq2.top().f;  
        pq2.pop();  
    }  
  
    int ans = -1;  
    for (int i = need; i < up; ++i) {  
        if (l[i] + r[i] + cow[i].f <= f && cow[i].s > ans){  
            ans = cow[i].s;  
        }  
    }  
    printf("%d\n", ans);  
    return 0;  
}  
