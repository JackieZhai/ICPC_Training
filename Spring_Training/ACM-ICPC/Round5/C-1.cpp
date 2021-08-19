#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long INF = 100000000000000LL;
const int N = 1005;
typedef long long ll;
long long n, m, X0, X1, Y0, Y1;
long long a[N * N], b[N * N], c[N * N], g[N][N], d[N];
int vis[N * N];

void build() {
    memset(vis, 0, sizeof(vis));
    a[0] = X0; a[1] = X1;
    b[0] = Y0; b[1] = Y1;
    g[1][2] = (a[1] * 90123 % 8475871 + b[1]) % 8475871 + 1;
    for (int i = 2; i < n * n; i++) {
	a[i] = (12345 + a[i - 1] * 23456 % 5837501 + a[i - 2] * 34567 % 5837501 + a[i - 1] * a[i - 2] % 5837501 * 45678 % 5837501) % 5837501;
	b[i] = (56789 + b[i - 1] * 67890 % 9860381 + b[i - 2] * 78901 % 9860381 + b[i - 1] * b[i - 2] % 9860381 * 89012 % 9860381) % 9860381;
	g[i / n + 1][i % n + 1] = (a[i] * 90123 % 8475871 + b[i]) % 8475871 + 1;
    }
    for (int i = 1; i <= n; i++)
	g[i][i] = 0;
}

void dijk() {
    int v[N];
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++)
	d[i] = INF;
    d[1] = 0;
    for (int i = 0; i < n; i++) {
	int x; long long m = INF;
	for (int y = 1; y <= n; y++) if (!v[y] && d[y] <= m) {m = d[y]; x = y;}
	v[x] = 1;
	for (int y = 1; y <= n; y++) d[y] = min(d[y], d[x] + g[x][y]);
    }
}

int main() {
    while (cin >> n >> m >> X0 >> X1 >> Y0 >> Y1) {
	build();
	dijk();

	for(int i=1; i<=n; i++)
        printf("--%lld", d[i]);

	for (int i = 2; i <= n; i++) {
	    vis[d[i] % m] = 1;
	}
	long long ans_v = INF;
	for (long long i = 0; i < m; i++) {
	    if (vis[i])
		ans_v = min(ans_v, i);
	}
	cout << ans_v << endl;
    }
    return 0;
}
