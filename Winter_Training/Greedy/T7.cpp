/*
练习题：Radar Installation_POJ 1328

贪心思路：把点转化为在x轴上的区间（即能保证覆盖该小岛的所有可能位置的集合）；
实现过程：先把这些线段按照左端小到大排序，
从第一个开始，放置下一个雷达的时候要同时在两线段范围内，并且尽可能往右放。 
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;


struct node  
{  
    double zuo, you;  
} fei[2100], t;  

int cmp(node a, node b)  
{  
    return a.zuo < b.zuo;  
}  

int x[2100],y[2100];  


int main()  
{  
    int i, j, n, d, num, flag, s=0;  
    double z, p;  
    while(scanf("%d%d",&n,&d)!=EOF)  
    {  
        if(n==0&&d==0) break;  
        s++;  
        flag=0;  
        for(i=0; i<n; i++)  
        {  
            scanf("%d%d",&x[i],&y[i]);  
            if(y[i]>d)  
                flag=1;  
        }  
        if(flag)  
            printf("Case %d: -1\n",s);  
        else  
        {  
            for(i=0; i<n; i++)  
            {  
                z=sqrt(d*d*1.0-y[i]*y[i]*1.0);  
                fei[i].zuo=(double)x[i]-z;  
                fei[i].you=(double)x[i]+z;  
            }  
            
            sort(fei,fei+n,cmp);
			  
            num=0;  
            p=-100000000;  
            for(i=0; i<n; i++)  
            {  
                if(fei[i].zuo>p)  
                {  
                    num++;  
                    p=fei[i].you;  
                }  
                else if(fei[i].you<p)  
                {  
                    p=fei[i].you;  
                }
                //else if(fei[i].zuo<p && fei[i].you>p)
                //	    	什么也不做(不调整雷达位置)
            }  
            printf("Case %d: %d\n",s,num);  
        }  
    }  
    return 0;  
}  
