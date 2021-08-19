/*
练习题：Osenbei_AOJ 0525

注：此题用了bitset 
由于行比较少，所以用dfs确定行的情况之后，再遍历确定最优的列。 
*/
#include <cstdio>  
#include <algorithm>  
#include <bitset>  
  
using namespace std;  
  
const int MAX_R = 10;  
const int MAX_C = 10000;  
  
int R, C;  
bitset<MAX_C> a[MAX_R];  
  
int ans;  
  
void dfs(int k){  
    if(k == R){  
        //row certain  
        int result = 0;            //the max value of this condition
        for(int j = 0; j < C; j ++){  
            int upNum = 0;            //up numbers counting
            for(int i = 0; i < R; i ++){  
                if(a[i][j]) upNum++;  
            }  
            result += max(upNum, R-upNum);  //Whether filp or not, choose bigger one
        }  
        ans = max(ans, result);  
        return;  
    }  
    //without fliping  
    dfs(k + 1);  
    //flip  
    a[k].flip();  
    dfs(k + 1);  
  
}  
  
void solve(){  
    ans = 0;  
    dfs(0);  
    printf("%d\n", ans);  
}  
  
int main(int argc, char const *argv[]){  
  
    while(scanf("%d %d", &R, &C)){  
        if(R == 0 && C == 0) break;  
  
        for(int i = 0; i < R; i ++){  
            for(int j = 0; j < C; j ++){  
                bool tmp;  
                scanf("%d", &tmp);  
                a[i][j] = tmp;  
            }  
        }  
        solve();  
    }  
  
    return 0;  
}  
