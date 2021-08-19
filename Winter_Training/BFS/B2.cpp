#include <bits/stdc++.h>
using namespace std;

string maze_name;  
int r0, c0, r1, c1, dir, r2, c2;  
  
const char* dirs = "NESW";  
const char* turns = "FLR";  
int dir_id(char c) {  
    return (strchr(dirs, c) - dirs);  
}  
int turn_id(char c) {  
    return (strchr(turns, c) - turns);  
}  
  
const int dr[] = {-1, 0, 1, 0};  
const int dc[] = {0, 1, 0, -1};  
  
const int maxn = 20;  
int has_edge[maxn][maxn][maxn][maxn];  
void read_edge() {  
    memset(has_edge, 0, sizeof(has_edge));  
    int pr, pc, pdir, pturn;  
    string temp;  
    while (cin >> pr) {  
        if (pr == 0) break;  
        cin >> pc;  
        while (cin >> temp) {  
            if (temp == "*") break;  
            pdir = dir_id(temp[0]);  
            for (int i = 1; i < temp.length(); i++) {  
                pturn = turn_id(temp[i]);  
                has_edge[pr][pc][pdir][pturn] = 1;  
            }  
        }  
    }  
}  
  
bool read_list() {  
    cin>>maze_name;  
    if (maze_name == "END") return false;  
    char dir0;  
    cin >> r0 >> c0 >> dir0 >> r2 >> c2;  
    dir = dir_id(dir0);  
    r1 = r0 + dr[dir];  
    c1 = c0 + dc[dir];  
    read_edge();  
    return true;  
}  
  
struct Node {  
    int r, c, dir;  
    Node(int r = 0, int c = 0, int dir = 0) : r(r), c(c), dir(dir) {}  
};  
  
int d[maxn][maxn][maxn];  
Node p[maxn][maxn][maxn];  
Node walk(const Node& u, int turn) {  
    int dir = u.dir;//改变朝向 
    if (turn == 1) dir = (dir + 3) % 4;  
    if (turn == 2) dir = (dir + 1) % 4;  
    //r + dr[dir], c + dc[dir]表示在(r, c)位置朝dir前进一格。  
    //向右转、向左转→先改变朝向，再r+dr[dir]、c+dc[dir]。  
    return Node(u.r + dr[dir], u.c + dc[dir], dir);  
}  
  
bool inside(int r, int c) {  
    if (r >= 1 && r <= 9 && c >= 1 && c <= 9)  
        return true;  
    return false;  
}  
  
void print_ans(Node u) {  
    //从目标结点逆序追溯到初始结点 
    vector<Node> nodes;  
    while (true) {  
        nodes.push_back(u);  
        if (d[u.r][u.c][u.dir] == 0) break;  
        u = p[u.r][u.c][u.dir];  
    }  
    nodes.push_back(Node(r0, c0, dir));  
    cout << maze_name << endl;  
    //打印解，每行10个 
    int cnt = 0;  
    for (int i = nodes.size() - 1; i >= 0; i--) {  
        if (cnt % 10 == 0) cout << " ";  
        cout << " (" << nodes[i].r << "," << nodes[i].c << ")";  
        if (++cnt % 10 == 0) cout << endl;  
    }  
    if (nodes.size() % 10 != 0) cout << endl;  
}  
  
//BFS的队列push和pop的思想没有变 
void bfs() {  
    queue<Node> q;  
    memset(d, -1, sizeof(d));  
    Node n1(r1, c1, dir);  
    q.push(n1);  
    d[r1][c1][dir] = 0;  
    while (!q.empty()) {  
        Node u = q.front(); q.pop();  
        if (u.r == r2 && u.c == c2) {  
            print_ans(u);  
            return;  
        }  
        for (int i = 0; i < 3; i++) {  
            Node v = walk(u, i);  
            if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {  
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;  
                p[v.r][v.c][v.dir] = u;  
                q.push(v);  
            }  
        }  
    }  
    cout << maze_name << endl;  
    cout << "  No Solution Possible" << endl;  
}  
  
int main() {  
    while (read_list()) {  
        bfs();  
    }  
    return 0;  
}  



/*
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
NOSOLUTION
3 1 N 3 2
1 1 WL NR *
1 2 NL ER *
2 1 SL WR NFR *
2 2 SR EL *
0
END
*/
