/*
练习题：X-factor Chains_POJ 3421
	题目数据量很大，不如先打一个素数表。 
*/

#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int maxp = 10000 + 7;
const int maxn = 1100000 + 7;

int sum,X;
int num[maxp],k; //存每个素因子的个数

//埃氏筛法(Sieve of Eratosthenes)
int prime[maxp]; //第i个素数，此为存放素数的数组 
bool is_prime[maxn]; //is_prime[]为true时为素数

//返回n以内素数的个数
int sieveErato(int n)
{
	for(int i=0; i<=n; i++)
		is_prime[i]=true;
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=2; i<=n; i++)
	{
		if(is_prime[i])
		{
			prime[sum++]=i;
			for(int j=2*i; j<=n; j+=i)
				is_prime[j]=false;
		}
	}
	return sum;
}



ll get_max(){  //得到最大链长，即素因子的个数
    ll ans=0;
    for(int i=0;i<k;i++)
        ans+=(ll)num[i];
    return ans;
}

ll get_sum(){  //得到链的种类数,即素因子的排列组合数
    ll fenzi=1;
    ll Max=get_max();
    for(ll i=2;i<=Max;i++)
        fenzi*=i; //最大链的阶乘 
    for(int i=0;i<k;i++){
        for(int j=2;j<=num[i];j++){
            fenzi/=(ll)j; //除以重复数的阶乘 
        }
    }
    return fenzi;
}

void solve(){
    k=0;
    memset(num,0,sizeof(num));
    //整数分解 
    for(int i=0;i<sum;i++){
        if(X%prime[i]==0){
            while(X%prime[i]==0){
                num[k]++;
                X/=prime[i];
            }
            k++;
        }
        if(X==1){
            break;
        }
    }
    ll ans_max=get_max();
    ll ans_sum=get_sum();
    printf("%I64d %I64d\n",ans_max,ans_sum);
}

int main(){
    sieveErato(maxn);
    while(scanf("%d",&X)!=EOF)
	{
        solve();
    }
	return 0;
}

