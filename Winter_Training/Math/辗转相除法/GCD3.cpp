/*
��ϰ�⣺Dead Fraction_POJ 1930 
	������ѭ��С����Ϊ��ĸ��С�ķ�����
	��Ŀָ����ʾ������û���ظ��Ĳ��֣�
	���Ի���XXX../999..���㷨Ӧ��ѭ���ڣ�
	��С�����ʼ������ÿһλ������ѭ���ڵ������ 
*/ 

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll __int64
using namespace std;
 
ll gcd(ll n,ll m)
{
	ll x;
	while(m)
	{
		x=n%m;
		n=m;
		m=x;
	}
	return n;
}

int main()
{
	int len,i,j,point,k;
	ll inter;
	char str[20];
	while(scanf("%s",str)&&strcmp(str,"0")!=0)
	{
		len=strlen(str);
		for(i=2;i<len;++i)
		{
			if(str[i]=='.')
			{
				point=i;//��¼���ֺ����һ������ֵ�λ�� 
				break;
			}
		}
		ll ans_num=0x3f3f3f3f,ans_cnt;
		for(i=2;i<point;++i)
		{
			j=i-2;//j��ʾС������ѭ���ڵĳ���
			ll cnt=0,num=0;
			for(k=i;k<point;++k)
			{
				cnt=cnt*10+(str[k]-'0');//���� 
				num=num*10+9;//��ĸ 
			}
			inter=0;
			for(k=2;k<i;++k)
				inter=inter*10+(str[k]-'0');//ѭ����ǰ������� 
			cnt+=inter*num;
			for(k=0;k<j;++k)
				num*=10;
			ll res=gcd(num,cnt);
			cnt/=res;
			num/=res;
			if(num<ans_num)//������С�ķ�ĸ 
			{
				ans_num=num;
				ans_cnt=cnt;
			}
		}
		printf("%I64d/%I64d\n",ans_cnt,ans_num);
	}
	return 0;
} 
