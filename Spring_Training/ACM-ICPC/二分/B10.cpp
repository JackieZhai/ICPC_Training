/*
��ϰ�⣺Median_POJ 3579
	ÿ�ζ����ҵ�m/2���ֵ
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1000007;

int n;
int x[maxn];
long long m;

bool C(int mid) 
{
    long long cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += x+n-lower_bound(x+i+1, x+n, x[i]+mid);  //���ֲ��� 
    return cnt <= m/2;  
}

int main() 
{
    while(scanf("%d", &n)!=EOF) 
	{
        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);
            
        sort(x, x+n);
        
        m = n*(n-1)/2;      //�����еĸ���ΪC(n,2)
        
        int L = 0, R = *max_element(x, x+n);
        while(R-L > 1) 
		{
            int mid = (L+R)/2;
            if(C(mid)) 
				R = mid;
            else 
				L = mid;
        }
        
        printf("%d\n", L);

    }
    return 0;
}

