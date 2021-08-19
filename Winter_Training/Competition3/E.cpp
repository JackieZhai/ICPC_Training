/*
	此题用差分约束的Bellman-Ford检查负圈的时候会TLE；(SPFA可以实现) 
	用拓扑排序更易
*/ 

#include <bits/stdc++.h>
using namespace std;

/*	TLE代码： 
const int MAX_N=10007, MAX_ML=20007, INF=0x3f3f3f3f;

int N, ML;
int AL[MAX_ML], BL[MAX_ML];
int d[MAX_N];

int main()
{
	while(scanf("%d%d", &N, &ML)!=EOF)
	{
	
		for(int i=0; i<ML; i++)
		{
			scanf("%d%d", &AL[i], &BL[i]);
		}
		bool flag=false;
		
		fill(d, d+N, 0);
		
		//Bellman-Ford
		for(int k=0; k<N; k++)
		{
			for(int i=0; i<ML; i++)
			{
					if(d[BL[i]-1]>d[AL[i]-1]-1)//权值为1
					{
						if(i==k-1) //检测负圈 
						{
							printf("-1\n");
							flag=true;
							break;
						}
						d[BL[i]-1]=d[AL[i]-1]-1;
					}
			}
			if(flag)
				break;
		}	
		if(flag)
			continue;

		int res=0, dif=0;
		long long ans=0;
		for(int i=0; i<N; i++)
			if(dif>d[i])
				dif=d[i];
		res=888-dif;
		for(int i=0; i<N; i++)
			ans+=res+d[i];
		printf("%lld\n", ans);
		
	}
	return 0;
}
*/



//数据范围较大，用邻接表 
int n;
int indegree[10005];
vector <int>  v[10005];

int topsort(){
    int i,j,tag;
    int countn = 0,q = 0;
    int tem[10005];
    int sum = n * 888;

    while(countn != n){
        tag = 0;
        for(i = 1;i <= n;i++){
            if(!indegree[i]){
                indegree[i] = -1;
                tem[tag] = i;
                tag++;
            }
        }
        if(!tag){
            return -1;
        }
        else{
            sum += q * tag;
            q++;
            countn += tag;
            for(i = 0;i < tag;i++){
                for(j = 0;j < v[tem[i]].size();j++){
                    indegree[v[tem[i]].at(j)]--;
                }
            }
        }
    }
    return sum;
}
int main()
{
    int m;
    int i,j;
    int a,b;

    while(scanf("%d%d",&n,&m) != EOF){
        for(i = 0;i < 10005;i++)
            v[i].clear();
        memset(indegree,0,sizeof(indegree));
        while(m--){
            scanf("%d%d",&a,&b);
            int flag = 0;
            for(i = 0;i < v[b].size();i++){
                if(v[b].at(i) == a)
                    flag = 1;
            }
            if(!flag){
                indegree[a]++;
                v[b].push_back(a);
            }
        }
        printf("%d\n",topsort());
    }
    return 0;
}

