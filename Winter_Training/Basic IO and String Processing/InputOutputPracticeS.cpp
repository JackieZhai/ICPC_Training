#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

string K[25], E[25], uK[25];


int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int count[25];
	int Kn, En, kase = 0;
	while(scanf("%d%d", &Kn, &En) != EOF)
	{
		getchar();
		kase++;
		for(int i=0; i<En; i++)
		{
			count[i] = 0;
			E[i].clear();
		}
		for(int i=0; i<Kn; i++)
		{
			K[i].clear();
			uK[i].clear();
		}
		for(int i=0; i<Kn; i++)
			getline(cin, K[i]);
		for(int i=0; i<Kn; i++)
//			transform(K[i].begin(), K[i].end(), back_inserter(uK[i]), ::toupper);
			for(int j=0; j!=K[i].size(); j++)
				uK[i].push_back(toupper(K[i][j]));
			
		for(int i=0; i<En; i++)
		{
			getline(cin, E[i]);
			string buf="";
			for(int ite=0; ite!=E[i].size(); ite++)
			{
				if(E[i][ite]<='Z'&&E[i][ite]>='A'||E[i][ite]>='a'&&E[i][ite]<='z')
				{
					buf.push_back(E[i][ite]);
				}
				else //if(E[i][ite]==' '||E[i][ite]=='"'||E[i][ite]=='.'||E[i][ite]==','||E[i][ite]=='!'||E[i][ite]=='?')
				{
					for(int j=0; j<Kn; j++)
						if(buf!=""&&(buf==K[j]||buf==uK[j]))
						{
							count[i]++;
							buf.clear();
							break;
						}
					buf.clear();
				}
			}
		}
		int max=0, maxn[25],ibuf=-1;
		memset(maxn, 0, sizeof(maxn));
		for(int i=0; i<En; i++)
		{
			if(max<count[i])
			{
				max = count[i];
				maxn[i] = 1;
				maxn[ibuf] = 0;
				ibuf = i;
			}
			else if(max==count[i])
			{
				maxn[i] = 1;
			}
		}
		
//		for(int i=0; i<En; i++)
//			cout<<count[i]<<" ";
//		cout<<endl;
//		for(int i=0; i<En; i++)
//			cout<<maxn[i]<<" ";
		
		printf("Excuse Set #%d\n", kase);
		for(int i=0; i<En; i++)
		{
			if(maxn[i]==1)
				cout<<E[i]<<endl;
		}
		printf("\n");
		
	}
	
	return 0;
}


