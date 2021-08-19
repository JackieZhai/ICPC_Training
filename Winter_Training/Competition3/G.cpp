/*
	康托展开区分各种形态 + BFS搜索路径 + dp多组数据打表 
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 5;
int vis[maxn];
string ans[maxn];

int fac[]={1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320};


int Cantor(string str)
{
    int ret = 0;
    int n = str.size();
    for(int i = 0 ; i < n ; i++) {
        int cnt = 0;
        for(int j = i ; j < n ; j++)
            if(str[j] < str[i])
                cnt++;
        ret += cnt * fac[n - i - 1];
    }
    return ret;
}


void move_A(string &str)
{
    for(int i = 0 ; i < 4 ; i++)
        swap(str[i] , str[7 - i]);
}
void move_B(string &str)
{
    for(int i = 3 ; i > 0 ; i--)
        swap(str[i] , str[i - 1]);
    for(int i = 4 ; i < 7 ; i++)
        swap(str[i] , str[i + 1]);
}
void move_C(string &str)
{
    char tmp = str[6];
    str[6] = str[5];
    str[5] = str[2];
    str[2] = str[1];
    str[1] = tmp;
}


void BFS(string str)
{
    memset(vis , 0 , sizeof(vis));
    queue <string> que;
    que.push(str);
    int x = Cantor(str);
    vis[x] = 1;
    ans[x] = "";
    while(!que.empty()) 
	{
        string u = que.front();
        que.pop();
        int i = Cantor(u);

        string tmp = u;
        move_A(tmp);
        int k = Cantor(tmp);
        if(!vis[k])
		{
            vis[k] = 1;
            que.push(tmp);
            ans[k] = ans[i] + 'A';
        }

        tmp = u;
        move_B(tmp);
        k = Cantor(tmp);
        if(!vis[k])
		{
            vis[k] = 1;
            que.push(tmp);
            ans[k] = ans[i] + 'B';
        }

        tmp = u;
        move_C(tmp);
        k = Cantor(tmp);
        if(!vis[k]) 
		{
            vis[k] = 1;
            que.push(tmp);
            ans[k] = ans[i] + 'C';
        }
    }
}


int main() 
{
    int a[10];
    string s , e;
    string start = ("12345678");
    BFS(start);
    while(cin >> s >> e)
    {
        for(int i = 0 ; i < 8 ; i++)
            a[s[i] - '0'] = i + 1;
        for(int i = 0 ; i < 8 ; i++)
            e[i] = a[e[i] - '0'] + '0';
        int k = Cantor(e);
        cout << ans[k] << endl;
    }
    return 0;
}
