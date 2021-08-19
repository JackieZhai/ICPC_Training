#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

string firs, secs;
ll ans1, ans2;

struct Node{
	ll a, b;
	Node(ll a, ll b):a(a), b(b){
	}
};


int main()
{
	while(cin>>firs)
	{
		if(firs=="#")
			break;
		
		deque<Node> p, q;
		ans1=0,ans2=0;
		
		while(cin>>secs)
		{
			if(secs=="E")
				break;
			else if(secs=="B")
			{
				ll a, b;
				scanf("%lld%lld", &a, &b);
				p.push_back(Node(a,b));
                q.push_back(Node(a,b));
			}
			else if(secs=="S")
			{
				ll a, b;
				scanf("%lld%lld", &a, &b);
				ans1+=a*b;
				for(ll i=a; i>0; )
				{
					ll j=p.back().a;
					ll k=p.back().b;
					p.pop_back();
					if(i>=j)
					{
						i-=j;
						ans1-=j*k;
					}
					else
					{
						ans1-=i*k;
						p.push_back(Node(j-i, k));
						i=0;
					}
				}
				
				ans2+=a*b;
				for(ll i=a; i>0; )
				{
					ll j=q.front().a;
					ll k=q.front().b;
					q.pop_front();
					if(i>=j)
					{
						i-=j;
						ans2-=j*k;
					}
					else
					{
						ans2-=i*k;
						q.push_front(Node(j-i, k));
						i=0;
					}
				}
			}
		}
		
		cout<<firs<<" ";
			if(ans2<ans1)
				cout<<"FBFS ";
			else
				cout<<"LBFS ";
			printf("%9.2lf\n", 0.01*min(ans1, ans2));
	}
	
	
	
	return 0;
}
