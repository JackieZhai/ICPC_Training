/*
练习题：Moo University - Financial Aid_POJ 2010
	此题关键在于建模：
将入学的学生按成绩排序，我们从这些学生中一旦选定中位数，那么必定是中位数前选择n/2个，
中位数后面选择n/2个学生。那么如何选择这n/2个学生呢？肯定是选择经济援助之和最少的学生。
考虑左边的n/2个学生，中位数选定的那个学生每向右移动一位，左边就多出一个学生的选择，
我们将这多出的一个学生丢进按经济援助从大到小排列的优先队列，
那么，优先队列的开头必定是需要援助最多的学生，把他pop掉，每一次都这么更新记录在l[i]即可。
同理，右边的n/2个学生也这么选择，把和记录在r[i]里。最终遍历一遍求和小于等于f，且中位数最大的即可。 
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
    int up = c - need; // 中位数能取到的上限 
  
    // 计算l[i]  
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
  
    // 计算r[i]  
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
