#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef AC
	freopen("data.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	//cin.tie(0);
	
	string tmp, s;
	int n;
	cin >> n;
	getline(cin, tmp);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		cout << s << endl;
		cout << "====" << endl;
	}
	return 0;
} 
