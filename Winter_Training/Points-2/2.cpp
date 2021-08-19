#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef AC
	freopen("data.txt", "r", stdin);
#endif
	string tmp, s;
	int n;
	cin >> n;
	getline(cin, tmp);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		cout << s << endl;
		cout << "----" << endl;
		stringstream ss(s);
		while (ss >> tmp) {
			cout << tmp << endl;
		}
		cout << "====" << endl;
	}
	return 0;
} 
