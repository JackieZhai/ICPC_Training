/*
º”¡∑Ã‚£∫Alignment_POJ 1836 
	
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

const int maxn = 1000 + 10;
const double INF = 1e100;

double a[maxn];
int d1[maxn], d2[maxn];

int main() 
{
    int n;

    while(cin>>n) {
        for(int i=0; i<n; i++) cin>>a[i];

        d1[0] = 1;
        for(int i=1; i<n; i++) {
            int m = 0;
            for(int j=0; j<i; j++) {
                if(a[j] < a[i] && m < d1[j]) m = d1[j];
            }
            d1[i] = m+1;
        }

        d2[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            int m = 0;
            for(int j=n-1; j>i; j--) {
                if(a[j] < a[i] && m < d2[j]) m = d2[j];
            }
            d2[i] = m+1;
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                ans = max(ans, d1[i]+d2[j]);
            }
        }
        printf("%d\n", n-ans);
    }


    return 0;
}
