/*
练习题：Seven Puzzle_AOJ 0121

由于题目输入的是多个case（高达1000），如果对每个case都运行一遍bfs就会TLE。
这时我们使用dp，只需要一次bfs将解空间算出来，以后每一个case去解空间去找就行了。 
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
 
map<string, int> dp;
int direction[4] = { 1, -1, 4, -4 };
 
void bfs()
{
	queue<string> que;
	que.push("01234567");
	dp["01234567"] = 0;
	while (!que.empty())
	{
		string now = que.front(); que.pop();
		// p是'0'的位置
		int p; 
		for (int j = 0; j < 8; ++j)
		{
			if (now[j] == '0')
			{
				p = j;
				break;
			}
		}
 
		for (int i = 0; i < 4; ++i)
		{
			int n = p + direction[i];
			if (0 <= n && n < 8 && 
				!(p == 3 && i == 0) && // 右上角不能再往右了 
				!(p == 4 && i == 1))   // 左下角不能再往左了 
			{
				string next = now;
				swap(next[p], next[n]);
				if (dp.find(next) == dp.end()) //如果未找到相同的情况，则加入map中 
				{
					dp[next] = dp[now] + 1;
					que.push(next);
				}
			}
		}
	}
}

int main()
{
 
	bfs();
	string line;
	while (getline(cin, line))
	{
		line.erase(remove(line.begin(), line.end(), ' '), line.end()); //去掉空格和换行符 
		cout << dp[line] << endl;
	}
 
	return 0;
}
