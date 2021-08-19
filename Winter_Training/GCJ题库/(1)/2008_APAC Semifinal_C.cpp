/*
	化连续为离散，在运用dp求解。 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_M = 17;
int M, X;
double P;
double dp[2][(1<<MAX_M)+1];

int main()
{
//	freopen("C-small-practice.in", "r", stdin);
//	freopen("C-small-practice.out", "w", stdout);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++)
	{
		scanf("%d%lf%d", &M, &P, &X);
		
		int n=1<<M;
		
		double *prv=dp[0], *nxt=dp[1];
		memset(prv, 0, sizeof(double)*(n+1));
		prv[n]=1.0;
		
		for(int r=0; r<M; r++)
		{
			for(int i=0; i<=n; i++)
			{
				int jub=min(i, n-i);
				double t=0.0;
				for(int j=0; j<=jub; j++)
				{
					t=max(t, P*prv[i+j]+(1-P)*prv[i-j]);
				}
				nxt[i]=t;
			}
			swap(prv, nxt);
		}
		
		int i= (ll)X*n/1000000;
		printf("Case #%d: %.6f\n", kase, prv[i]);
	}
	return 0;
}
