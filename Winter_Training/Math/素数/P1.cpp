//��������ľ�Ϊ�������������㷨
//���Ӷȣ�O(��n)

//���Բ��ԣ�
bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1������
}

//Miller-Rabin���ԣ�
//Ϊ����߲��Ե���ȷ�ԣ�����ѡ��ͬ��a[]���ж�β���
//���Ӷȣ�O(logn)
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
    int t=mod_pow(a, d, n); //������
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
    int a[]={2, 3, 61}; //���Լ�������Ĳ��Է�Χ��Ҫ����Ĳ��Լ�
    for(int i=0; i<=2; i++)
        if(!MR_test(n, a[i], n-1))
            return false;
    return true;
}


//Լ��ö�٣���Լ������һ��vector��
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

//�����ֽ⣺���ֽ��������map���±��У�mapֵΪ���ӵĸ���
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


//���룺n���ֽ������
//�����tot��ͬ�������ĸ�����a[]��i����������ֵ��b[]��i����������ָ��
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
