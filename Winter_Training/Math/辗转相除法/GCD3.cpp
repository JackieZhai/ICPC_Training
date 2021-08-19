/*
练习题：Dead Fraction_POJ 1930 
	把无限循环小数变为分母最小的分数，
	题目指出显示的内容没有重复的部分，
	所以会有XXX../999..的算法应对循环节，
	从小数点后开始，遍历每一位后面是循环节的情况。 
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
				point=i;//记录数字后面第一个点出现的位置 
				break;
			}
		}
		ll ans_num=0x3f3f3f3f,ans_cnt;
		for(i=2;i<point;++i)
		{
			j=i-2;//j表示小数点后非循环节的长度
			ll cnt=0,num=0;
			for(k=i;k<point;++k)
			{
				cnt=cnt*10+(str[k]-'0');//分子 
				num=num*10+9;//分母 
			}
			inter=0;
			for(k=2;k<i;++k)
				inter=inter*10+(str[k]-'0');//循环节前面的数字 
			cnt+=inter*num;
			for(k=0;k<j;++k)
				num*=10;
			ll res=gcd(num,cnt);
			cnt/=res;
			num/=res;
			if(num<ans_num)//更新最小的分母 
			{
				ans_num=num;
				ans_cnt=cnt;
			}
		}
		printf("%I64d/%I64d\n",ans_cnt,ans_num);
	}
	return 0;
} 
