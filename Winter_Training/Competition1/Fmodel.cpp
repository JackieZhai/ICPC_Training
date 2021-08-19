#include <iostream>  
#include <cstdio>  
#include <cmath>  
using namespace std;  
typedef long long LL;  
const LL INF = 9e15;  
  
struct p{  
    LL x, y;  
    char ch;  
}v[9];  
  
int main()  
{  
   
    ios::sync_with_stdio(false); 
	cin.tie(0);  
  
  
    LL n, x0, y0, x, y;  
    char ch;  
    cin >> n;  
    cin >> x0 >> y0;  
  
    v[1].x = -INF; v[1].y = y0;  
    v[2].x = INF; v[2].y = y0;  
    v[3].x = x0; v[3].y = -INF;  
    v[4].x = x0; v[4].y = INF;  
    v[5].x = -INF; v[5].y = -INF;  
    v[6].x = INF; v[6].y = -INF;  
    v[7].x = INF; v[7].y = INF;  
    v[8].x = -INF; v[8].y = INF;  
  
    for(int i = 0; i < n; i++){  
        cin >> ch;//cout << ch << endl;  
        cin >> x >> y;  
  
        if(abs(x0 - x) == abs(y0 - y)){  
            if(x0 - x < 0){  
                if(y0 - y < 0){  
                    if(v[7].x > x){  
                        v[7].x = x;  
                        v[7].y = y;  
                        v[7].ch = ch;  
                    }  
                }  
                else{  
                    if(v[6].x > x){  
                        v[6].x = x;  
                        v[6].y = y;  
                        v[6].ch = ch;  
                    }  
                }  
            }  
            else{  
                if(y0 - y < 0){  
                    if(v[8].x < x){  
                        v[8].x = x;  
                        v[8].y = y;  
                        v[8].ch = ch;  
                    }  
                }  
                else{  
                    if(v[5].x < x){  
                        v[5].x = x;  
                        v[5].y = y;  
                        v[5].ch = ch;  
                    }  
                }  
            }  
        }  
  
        if(x0 == x){  
            if(y0 - y > 0){  
                if(v[3].y < y){  
                    v[3].y = y;  
                    v[3].x = x;  
                    v[3].ch = ch;  
                }  
            }  
            else{  
                if(v[4].y > y){  
                    v[4].y = y;  
                    v[4].x = x;  
                    v[4].ch = ch;  
                }  
            }  
        }  
  
        if(y0 == y){  
            if(x0 - x > 0){  
                if(v[1].x < x){  
                    v[1].x = x;  
                    v[1].y = y;  
                    v[1].ch = ch;  
                }  
            }  
            else{  
                if(v[2].x > x){  
                    v[2].x = x;  
                    v[2].y = y;  
                    v[2].ch = ch;  
                }  
            }  
        }  
    }  
  
    bool ans = false;  
    for(int i = 1; i <= 4; i++){  
        if(v[i].x == INF || v[i].y == INF || v[i].x == -INF || v[i].y == -INF) continue;  
        if(v[i].ch == 'R' || v[i].ch == 'Q'){  
            //cout << v[i].x << " " << v[i].y << " " << v[i].ch << endl;  
            ans = true;  
            break;  
        }  
    }  
  
    for(int i = 5; i <= 8; i++){  
        if(v[i].x == INF || v[i].y == INF || v[i].x == -INF || v[i].y == -INF) continue;  
        if(v[i].ch == 'B' || v[i].ch == 'Q'){  
            //cout << v[i].x << " " << v[i].y << " " << v[i].ch << endl;  
            ans = true;  
            break;  
        }  
    }  
  
    if(ans) cout << "YES" << endl;  
    else cout << "NO" << endl;  
    return 0;  
}  
