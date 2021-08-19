#include <bits/stdc++.h>
using namespace std;

int n, m;
char inp[1007][17];
char outp[1007][17];
int ini[1007][4];
int outi[1007][4];
string buf;


int main()
{
	scanf("%d%d", &n,  &m);
	getchar();
	for(int i=0; i<n; i++)
	{
		scanf("%s", inp[i]);
		getchar();
		getline(cin, buf, '.');
		ini[i][0]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			ini[i][0]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				ini[i][0]+=(buf[buf.size()-3]-'0')*100;
		}
		getline(cin, buf, '.');
		ini[i][1]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			ini[i][1]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				ini[i][1]+=(buf[buf.size()-3]-'0')*100;
		}
		getline(cin, buf, '.');
		ini[i][2]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			ini[i][2]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				ini[i][2]+=(buf[buf.size()-3]-'0')*100;
		}
		getline(cin, buf);
		ini[i][3]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			ini[i][3]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				ini[i][3]+=(buf[buf.size()-3]-'0')*100;
		}
	}
	for(int i=0; i<m; i++)
	{
		scanf("%s", outp[i]);
		getchar();
		getline(cin, buf, '.');
		outi[i][0]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			outi[i][0]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				outi[i][0]+=(buf[buf.size()-3]-'0')*100;
		}
		getline(cin, buf, '.');
		outi[i][1]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			outi[i][1]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				outi[i][1]+=(buf[buf.size()-3]-'0')*100;
		}
		getline(cin, buf, '.');
		outi[i][2]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			outi[i][2]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				outi[i][2]+=(buf[buf.size()-3]-'0')*100;
		}
		getline(cin, buf, ';');
		outi[i][3]+=(buf[buf.size()-1]-'0');
		if(buf.size()>=2)
		{
			outi[i][3]+=(buf[buf.size()-2]-'0')*10;
			if(buf.size()>=3)
				outi[i][3]+=(buf[buf.size()-3]-'0')*100;
		}
		getchar();
	}
	
	for(int i=0; i<m; i++)
	{
		int k;
		for(int j=0; j<n; j++)
		{
			if(outi[i][0]==ini[j][0]&&outi[i][1]==ini[j][1]&&outi[i][2]==ini[j][2]&&outi[i][3]==ini[j][3])
			{
				k=j;
				break;
			}
		}
		printf("%s %d.%d.%d.%d; #%s\n", outp[i], outi[i][0], outi[i][1], outi[i][2], outi[i][3], inp[k]);
		
		
	}
	
	
	return 0;
}
