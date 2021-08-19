//假设输入的均为正数，这三个算法
//复杂度：O(√n)

//素性测试：
bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1是例外
}

//Miller-Rabin测试：
//为了提高测试的正确性，可以选择不同的a[]进行多次测试
//复杂度：O(logn)
bool MR_test(int n, int a, int d)
{
    if(n==2)
        return true;
    if(n==a)
        return true;
    if((n&1)==0)
        return false;
    while(!(d&1))
        d=d>>1;
    int t=mod_pow(a, d, n); //快速幂
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(long long)t*t%n;
        d=d<<1;
    }
    return (t==n-1 || (d&1)==1);
}
bool is_prime(int n)
{
    if(n<2)
        return false;
    int a[]={2, 3, 61}; //测试集，更广的测试范围需要更大的测试集
    for(int i=0; i<=2; i++)
        if(!MR_test(n, a[i], n-1))
            return false;
    return true;
}


//约数枚举：将约数存入一个vector中
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

//整数分解：将分解的数存入map的下标中，map值为因子的个数
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


//输入：n待分解的整数
//输出：tot不同质因数的个数，a[]第i个质因数的值，b[]第i个质因数的指数
void prime_factor(int n, int a[MAX_N], int b[MAX_N], int &tot)
{
    int temp, i, now;
    temp=(int)((double)sqrt(n)+1);
    tot=0;
    now=n;
    for(i=2; i<=temp; i++)
        if(now%i==0)
        {
            a[++tot]=i;
            b[tot]=0;
            while(now%i==0)
            {
                ++b[tot];
                now/=i;
            }
        }
    if(now!=1)
    {
        a[++tot]=now;
        b[tot]=1;
    }
}
