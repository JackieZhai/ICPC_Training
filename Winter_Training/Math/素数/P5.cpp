/*
��ϰ�⣺X-factor Chains_POJ 3421
	��Ŀ�������ܴ󣬲����ȴ�һ�������� 
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
int num[maxp],k; //��ÿ�������ӵĸ���

//����ɸ��(Sieve of Eratosthenes)
int prime[maxp]; //��i����������Ϊ������������� 
bool is_prime[maxn]; //is_prime[]ΪtrueʱΪ����

//����n���������ĸ���
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



ll get_max(){  //�õ�����������������ӵĸ���
    ll ans=0;
    for(int i=0;i<k;i++)
        ans+=(ll)num[i];
    return ans;
}

ll get_sum(){  //�õ�����������,�������ӵ����������
    ll fenzi=1;
    ll Max=get_max();
    for(ll i=2;i<=Max;i++)
        fenzi*=i; //������Ľ׳� 
    for(int i=0;i<k;i++){
        for(int j=2;j<=num[i];j++){
            fenzi/=(ll)j; //�����ظ����Ľ׳� 
        }
    }
    return fenzi;
}

void solve(){
    k=0;
    memset(num,0,sizeof(num));
    //�����ֽ� 
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

