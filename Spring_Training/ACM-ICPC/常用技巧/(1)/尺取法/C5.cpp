/*
¡∑œ∞Ã‚£∫Graveyard Design_POJ 2100
	
*/
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ULL;

int main()
{
	ULL n;
	vector<pair<ULL, ULL> > answer;
	
	while (cin >> n)
	{
		ULL l = 1, r = 1, sum = 0, sq = 0;
		for (;;)
		{
			while (sum < n)
			{
				sq = r * r;
				sum += sq;
				++r;
			}
			if (sq > n)
			{
				break;
			}
			if (sum == n)
			{
				answer.push_back(make_pair(l, r));
			}
			sum -= l * l;
			++l;
		}
		
		
		
		cout << answer.size() << endl;
		for (vector<pair<ULL, ULL> >::const_iterator it = answer.begin(); it != answer.end(); ++it)
		{
			int b = it->first, e = it->second;
			cout << e - b << ' ';
			for (int i = b; i < e; ++i)
			{
				cout << i << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
