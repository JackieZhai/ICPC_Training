///��ѧ���


///շת�����
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}


///�������
long long int MOD = 1e9+7;
long long int c[2010][2010];


	for(int i = 0; i < 2005; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1; i < 2005; i++)
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;


///����������
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod)
{
	ll res=1;
	while(n>0)
	{
		if(n&1)
			res=res*x%mod; //������������λΪ1�������x^(2^i)
		x=x*x%mod; //��xƽ��
		n>>=1;
	}
	return res;
}


///����ɸ��(Sieve of Eratosthenes)
int prime[MAX_N]; //��i����������Ϊ�������������
bool is_prime[MAX_N]; //is_prime[]ΪtrueʱΪ����

//����n���������ĸ���
int sieveErato(int n)
{
	int p=0;
	for(int i=0; i<=n; i++)
		is_prime[i]=true;
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=2; i<=n; i++)
	{
		if(is_prime[i])
		{
			prime[p++]=i;
			for(int j=2*i; j<=n; j+=i)
				is_prime[j]=false;
		}
	}
	return p;
}


///���Բ��ԣ�
bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1������
}


///Լ��ö�٣���Լ������һ��vector��
vector<int> divisor(int n)
{
	vector<int> res;
	for(int i=1; i*i<=n; i++)
	{
		if(n%i==0)
		{
			res.push_back(i);
			if(i!=n/i)
				res.push_back(n/i);
		}
	}
	return res;
}

///�����ֽ⣺���ֽ��������map���±��У�mapֵΪ���ӵĸ���
map<int, int> prime_factor(int n)
{
	map<int, int> res;
	for(int i=2; i*i<=n; i++)
	{
		while(n%i==0)
		{
			++res[i];
			n/=i;
		}
	}
	if(n!=1)
		res[n]=1;
	return res;
}

/*
���ؼ���������⣺
	��n����Ʒ����i����Ʒ��ai������ͬ�������Ʒ���Ի������ֵ���ͬ����Ĳ��У�
	������ȡ��m�����ж�����ȡ�����󷽷���ģM��ֵ��
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[MAX_N];

int dp[MAX_N][MAX_M];

void solve()
{
	//һ������ȡ�÷�������ֻ��һ��
	for(int i=0; i<=n; i++)
		dp[i][0]=1;
	for(int i=0; i<n; i++)
		for(int j=1; j<=m; j++)
			if(j-1-a[i+1]>=0)
			//����ȡ�������£�Ҫ�����������Ľ�����ָ���
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i+1]]+M)%M;
			else
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
}


/*
���������⣺
	��n�����������Ʒ�������ǻ��ֳɲ�����m�飬�󻮷ַ�����ģM��������
	1<=m<=n<=1000, 2<=M<=10000
	(����Ϊn��m����)
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_M=1007, MAX_N=1007;
const int M=1e9+7;

int n, m;
int dp[MAX_M][MAX_N];

void solve()
{
	dp[0][0]=1;
	for(int i=1; i<=m; i++)
		for(int j=0; j<=n; j++)
		{
			if(j-i>=0)
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
			else
				dp[i][j]=dp[i-1][j];
		}
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		solve();
		printf("%d %d\n", dp[m][n], dp[m-1][n]);
	}

	return 0;
}


/*
�����⣺Joseph_POJ 1012
	�����Լɪ�����⣬�ҳ�����ʽ��
	dp[i]��ʾΪ��i��ɱ��˭��
	dp[i]=(dp[i-1]+m-1)%(n-i+1).
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int J[14];
int dp[29];

int main()
{
	for(int k=1; k<14; k++)
	{
		int total=2*k;
		int m=1;
		for(int i=1; i<=k; i++)
		{
			dp[i]=(dp[i-1]+m-1)%(total-i+1);
			if(dp[i]<=k-1)
			{
				m++;
				i=0;
			}
		}
		J[k]=m;
	}

	int k;
	while(scanf("%d", &k)!=EOF)
	{
		if(k==0)
			break;

		printf("%d\n", J[k]);
	}

	return 0;
}
