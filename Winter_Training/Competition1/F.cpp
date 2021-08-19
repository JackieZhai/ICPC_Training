#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef pair<llint, llint> P;
vector<P> rook;
vector<P> bishop;
vector<P> queen;

int main()
{
	int n;
	scanf("%d", &n);
	P king;
	scanf("%lld%lld", &king.first, &king.second);
	while(n--)
	{
		getchar();
		char type;
		scanf("%c", &type);
		if(type=='B'){
			P buf;
			scanf("%lld%lld", &buf.first, &buf.second);
			bishop.push_back(buf);
		}else if(type=='R'){
			P buf;
			scanf("%lld%lld", &buf.first, &buf.second);
			rook.push_back(buf);
		}else if(type=='Q'){
			P buf;
			scanf("%lld%lld", &buf.first, &buf.second);
			queen.push_back(buf);
		}
	}
	
	bool flagr = false;
	for(int i=0; i<rook.size(); i++)
	{
		if(rook[i].first!=king.first&&rook[i].second!=king.second)
			continue;
		else
		{
			flagr = true;
			P dis = {abs(king.first-rook[i].first), abs(king.second-rook[i].second)};
			P dism;
			for(int j=0; j<rook.size(); j++)
			{
				dism.first = rook[j].first-rook[i].first;
				dism.second = rook[j].second-rook[i].second;
				if(dism.first==0&&dism.second==0)
					continue;
				else if(dism.first<dis.first&&dism.first>0&&dis.first>0&&rook[j].second==rook[i].second)
					flagr = false;
				else if(dism.first>dis.first&&dism.first<0&&dis.first<0&&rook[j].second==rook[i].second)
					flagr = false;
				else if(dism.second<dis.second&&dism.second>0&&dis.second>0&&rook[j].first==rook[i].first)
					flagr = false;
				else if(dism.second>dis.second&&dism.second<0&&dis.second<0&&rook[j].first==rook[i].first)
					flagr = false;
			}
			for(int j=0; j<queen.size(); j++)
			{
				dism.first = queen[j].first-rook[i].first;
				dism.second = queen[j].second-rook[i].second;
				if(dism.first<dis.first&&dism.first>0&&dis.first>0&&queen[j].second==rook[i].second)
					flagr = false;
				else if(dism.first>dis.first&&dism.first<0&&dis.first<0&&queen[j].second==rook[i].second)
					flagr = false;
				else if(dism.second<dis.second&&dism.second>0&&dis.second>0&&queen[j].first==rook[i].first)
					flagr = false;
				else if(dism.second>dis.second&&dism.second<0&&dis.second<0&&queen[j].first==rook[i].first)
					flagr = false;
			}
			for(int j=0; j<bishop.size(); j++)
			{
				dism.first = bishop[j].first-rook[i].first;
				dism.second = bishop[j].second-rook[i].second;
				if(dism.first<dis.first&&dism.first>0&&dis.first>0&&bishop[j].second==rook[i].second)
					flagr = false;
				else if(dism.first>dis.first&&dism.first<0&&dis.first<0&&bishop[j].second==rook[i].second)
					flagr = false;
				else if(dism.second<dis.second&&dism.second>0&&dis.second>0&&bishop[j].first==rook[i].first)
					flagr = false;
				else if(dism.second>dis.second&&dism.second<0&&dis.second<0&&bishop[j].first==rook[i].first)
					flagr = false;
			}
		}
	}
	
//	if(flagr)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	
	bool flagb = false;
	for(int i=0; i<bishop.size(); i++)
	{
		if(abs(bishop[i].first-king.first)!=abs(bishop[i].second-king.second))
			continue;
		else
		{
			flagb = true;
			P dis = {king.first-bishop[i].first, king.second-bishop[i].second};
			P dism;
			for(int j=0; j<rook.size(); j++)
			{
				dism.first = rook[j].first-bishop[i].first;
				dism.second = rook[j].second-bishop[i].second;
				if(abs(dism.first)==abs(dism.second))
				{
					if(dism.first>0&&dis.first>0&&dism.second>0&&dis.second>0&&dism.first<dis.first&&dism.second<dis.second)
						flagb = false;
					else if(dism.first>0&&dis.first>0&&dism.second<0&&dis.second<0&&dism.first<dis.first&&dism.second>dis.second)
						flagb = false;
					else if(dism.first<0&&dis.first<0&&dism.second>0&&dis.second>0&&dism.first>dis.first&&dism.second<dis.second)
						flagb = false;
					else if(dism.first<0&&dis.first<0&&dism.second<0&&dis.second<0&&dism.first>dis.first&&dism.second>dis.second)
						flagb = false;
				}
			}
			for(int j=0; j<queen.size(); j++)
			{
				dism.first = queen[j].first-bishop[i].first;
				dism.second = queen[j].second-bishop[i].second;
				if(abs(dism.first)==abs(dism.second))
				{
					if(dism.first>0&&dis.first>0&&dism.second>0&&dis.second>0&&dism.first<dis.first&&dism.second<dis.second)
						flagb = false;
					else if(dism.first>0&&dis.first>0&&dism.second<0&&dis.second<0&&dism.first<dis.first&&dism.second>dis.second)
						flagb = false;
					else if(dism.first<0&&dis.first<0&&dism.second>0&&dis.second>0&&dism.first>dis.first&&dism.second<dis.second)
						flagb = false;
					else if(dism.first<0&&dis.first<0&&dism.second<0&&dis.second<0&&dism.first>dis.first&&dism.second>dis.second)
						flagb = false;
				}
			}
			for(int j=0; j<bishop.size(); j++)
			{
				dism.first = bishop[j].first-bishop[i].first;
				dism.second = bishop[j].second-bishop[i].second;
				if(dism.first==0&&dism.second==0)
					continue;
				else if(abs(dism.first)==abs(dism.second))
				{
					if(dism.first>0&&dis.first>0&&dism.second>0&&dis.second>0&&dism.first<dis.first&&dism.second<dis.second)
						flagb = false;
					else if(dism.first>0&&dis.first>0&&dism.second<0&&dis.second<0&&dism.first<dis.first&&dism.second>dis.second)
						flagb = false;
					else if(dism.first<0&&dis.first<0&&dism.second>0&&dis.second>0&&dism.first>dis.first&&dism.second<dis.second)
						flagb = false;
					else if(dism.first<0&&dis.first<0&&dism.second<0&&dis.second<0&&dism.first>dis.first&&dism.second>dis.second)
						flagb = false;
				}
			}
		}
	}
	
//	if(flagb)
//		printf("YES\n");
//	else
//		printf("NO\n");
	
	
	bool flagq = false, flagq2 = false;
	for(int i=0; i<queen.size(); i++)
	{
		if(queen[i].first!=king.first&&queen[i].second!=king.second)
			;
		else
		{
			flagq = true;
			P dis = {abs(king.first-queen[i].first), abs(king.second-queen[i].second)};
			P dism;
			for(int j=0; j<rook.size(); j++)
			{
				dism.first = rook[j].first-queen[i].first;
				dism.second = rook[j].second-queen[i].second;
				if(dism.first<dis.first&&dism.first>0&&dis.first>0&&rook[j].second==queen[i].second)
					flagq = false;
				else if(dism.first>dis.first&&dism.first<0&&dis.first<0&&rook[j].second==queen[i].second)
					flagq = false;
				else if(dism.second<dis.second&&dism.second>0&&dis.second>0&&rook[j].first==queen[i].first)
					flagq = false;
				else if(dism.second>dis.second&&dism.second<0&&dis.second<0&&rook[j].first==queen[i].first)
					flagq = false;
			}
			for(int j=0; j<queen.size(); j++)
			{
				dism.first = queen[j].first-queen[i].first;
				dism.second = queen[j].second-queen[i].second;
				if(dism.first==0&&dism.second==0)
					continue;
				else if(dism.first<dis.first&&dism.first>0&&dis.first>0&&queen[j].second==queen[i].second)
					flagq = false;
				else if(dism.first>dis.first&&dism.first<0&&dis.first<0&&queen[j].second==queen[i].second)
					flagq = false;
				else if(dism.second<dis.second&&dism.second>0&&dis.second>0&&queen[j].first==queen[i].first)
					flagq = false;
				else if(dism.second>dis.second&&dism.second<0&&dis.second<0&&queen[j].first==queen[i].first)
					flagq = false;
			}
			for(int j=0; j<bishop.size(); j++)
			{
				dism.first = bishop[j].first-queen[i].first;
				dism.second = bishop[j].second-queen[i].second;
				if(dism.first<dis.first&&dism.first>0&&dis.first>0&&bishop[j].second==queen[i].second)
					flagq = false;
				else if(dism.first>dis.first&&dism.first<0&&dis.first<0&&bishop[j].second==queen[i].second)
					flagq = false;
				else if(dism.second<dis.second&&dism.second>0&&dis.second>0&&bishop[j].first==queen[i].first)
					flagq = false;
				else if(dism.second>dis.second&&dism.second<0&&dis.second<0&&bishop[j].first==queen[i].first)
					flagq = false;
			}
		}
		
		if(abs(queen[i].first-king.first)!=abs(queen[i].second-king.second))
			continue;
		else
		{
			flagq2 = true;
			P dis = {king.first-queen[i].first, king.second-queen[i].second};
			P dism;
			for(int j=0; j<rook.size(); j++)
			{
				dism.first = rook[j].first-queen[i].first;
				dism.second = rook[j].second-queen[i].second;
				if(abs(dism.first)==abs(dism.second))
				{
					if(dism.first>0&&dis.first>0&&dism.second>0&&dis.second>0&&dism.first<dis.first&&dism.second<dis.second)
						flagq2 = false;
					else if(dism.first>0&&dis.first>0&&dism.second<0&&dis.second<0&&dism.first<dis.first&&dism.second>dis.second)
						flagq2 = false;
					else if(dism.first<0&&dis.first<0&&dism.second>0&&dis.second>0&&dism.first>dis.first&&dism.second<dis.second)
						flagq2 = false;
					else if(dism.first<0&&dis.first<0&&dism.second<0&&dis.second<0&&dism.first>dis.first&&dism.second>dis.second)
						flagq2 = false;
				}
			}
			for(int j=0; j<queen.size(); j++)
			{
				dism.first = queen[j].first-queen[i].first;
				dism.second = queen[j].second-queen[i].second;
				if(dism.first==0&&dism.second==0)
					continue;
				else if(abs(dism.first)==abs(dism.second))
				{
					if(dism.first>0&&dis.first>0&&dism.second>0&&dis.second>0&&dism.first<dis.first&&dism.second<dis.second)
						flagq2 = false;
					else if(dism.first>0&&dis.first>0&&dism.second<0&&dis.second<0&&dism.first<dis.first&&dism.second>dis.second)
						flagq2 = false;
					else if(dism.first<0&&dis.first<0&&dism.second>0&&dis.second>0&&dism.first>dis.first&&dism.second<dis.second)
						flagq2 = false;
					else if(dism.first<0&&dis.first<0&&dism.second<0&&dis.second<0&&dism.first>dis.first&&dism.second>dis.second)
						flagq2 = false;
				}
			}
			for(int j=0; j<bishop.size(); j++)
			{
				dism.first = bishop[j].first-queen[i].first;
				dism.second = bishop[j].second-queen[i].second;
				if(abs(dism.first)==abs(dism.second))
				{
					if(dism.first>0&&dis.first>0&&dism.second>0&&dis.second>0&&dism.first<dis.first&&dism.second<dis.second)
						flagq2 = false;
					else if(dism.first>0&&dis.first>0&&dism.second<0&&dis.second<0&&dism.first<dis.first&&dism.second>dis.second)
						flagq2 = false;
					else if(dism.first<0&&dis.first<0&&dism.second>0&&dis.second>0&&dism.first>dis.first&&dism.second<dis.second)
						flagq2 = false;
					else if(dism.first<0&&dis.first<0&&dism.second<0&&dis.second<0&&dism.first>dis.first&&dism.second>dis.second)
						flagq2 = false;
				}
			}
		}
	}
	
//	if(flagq||flagq2)
//		printf("YES\n");
//	else
//		printf("NO\n");
	
	
	if(flagb||flagq||flagr||flagq2)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
