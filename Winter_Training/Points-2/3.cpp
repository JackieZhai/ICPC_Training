#include<bits/stdc++.h>
using namespace std;

template<typename out_type, typename in_value>
out_type convert(const in_value & t) {
	stringstream stream;
	stream << t;
	out_type result;
	stream >> result;
	return result;
}

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
		//	cout << tmp << endl;
			int val = convert<int>(tmp);
			cout << val << endl;
		}
		cout << "----" << endl;
		cout << "====" << endl;
	}
	return 0;
} 
