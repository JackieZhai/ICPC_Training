/*
练习题：Sunscreen_POJ 3614 

此题关键是模型的建立：
都排序后，从最少的用起即可。 
*/
#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cstdio>  
#include <map>  
#include <vector>  
#include <queue>  
#define MAXN 2555  
#define INF 1000000007  
using namespace std;

int C, L;  
typedef pair<int, int> P;  

//由小到大排列的优先队列 
priority_queue<int, vector<int>, greater<int> > q;  
P cow[MAXN], bot[MAXN];  
int main()  
{  
    scanf("%d%d", &C, &L);  
    for(int i = 0; i < C; i++)
		scanf("%d%d", &cow[i].first, &cow[i].second);  
    for(int i = 0; i < L; i++)
		scanf("%d%d", &bot[i].first, &bot[i].second);
	
    sort(cow, cow + C);  
    sort(bot, bot + L); 
	 
    int j = 0, ans = 0;  
    for(int i = 0; i < L; i++)  
    {  
        while(j < C && cow[j].first <= bot[i].first)  
        {  
            q.push(cow[j].second);  
            j++;  
        }  
        while(!q.empty() && bot[i].second)  
        {  
            int x = q.top();  //先用终点小的 
            q.pop();  
            if(x < bot[i].first)
				continue;  
            ans++;  
            bot[i].second--;  
        }  
    }  
    printf("%d\n", ans);  
    return 0;  
}  
