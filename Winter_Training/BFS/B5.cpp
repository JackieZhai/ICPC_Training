/*
��ϰ�⣺Seven Puzzle_AOJ 0121

������Ŀ������Ƕ��case���ߴ�1000���������ÿ��case������һ��bfs�ͻ�TLE��
��ʱ����ʹ��dp��ֻ��Ҫһ��bfs����ռ���������Ժ�ÿһ��caseȥ��ռ�ȥ�Ҿ����ˡ� 
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
		// p��'0'��λ��
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
				!(p == 3 && i == 0) && // ���Ͻǲ����������� 
				!(p == 4 && i == 1))   // ���½ǲ����������� 
			{
				string next = now;
				swap(next[p], next[n]);
				if (dp.find(next) == dp.end()) //���δ�ҵ���ͬ������������map�� 
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
		line.erase(remove(line.begin(), line.end(), ' '), line.end()); //ȥ���ո�ͻ��з� 
		cout << dp[line] << endl;
	}
 
	return 0;
}
