//����ɸ��(Sieve of Eratosthenes)
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







//����ɸ��(Segment Sieve)��������ҿ�����[a,b)�ڵ�����
typedef long long ll;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//������[a,b)�ڵ�����ʵ��ɸ����is_prime[i-a]=true��i������
void sieveSeg(ll a, ll b)
{
	for(int i=0; (ll)i*i<b; i++)
		is_prime_small[i]=true;
	for(int i=0; i<b-a; i++)
		is_prime[i]=true;
	
	for(int i=2; (ll)i*i<b; i++)
	{
		if(is_prime_small[i])
		{
			for(int j=2*i; (ll)j*j<b; j+=i)
				is_prime_small[j]=false; //ɸ[2,��b)
			for(ll j=max(2LL, (a+i-1)/i)*i; j<b; j+=i)
				is_prime[j-a]=false;  //ɸ[a,b)
		}
	}
}











 

