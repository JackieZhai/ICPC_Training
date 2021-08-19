/*
练习题：Hopscotch_POJ 3050

此题运用dfs在方格中行走，利用传参的形式记录步数和数列种类(由于只有六位)。 
*/
#include <cstdio>  
#include <set>  
using namespace std;  
  
int grid[6][6];  
int dx[4] = {-1, 0, 1, 0};  
int dy[4] = {0, -1, 0, 1};  

//运用set(而不是multiset)避免重复计数 
set<int> digit;
  
void dfs(int x, int y, int step, int num)  
{  
    if (step == 5) {  
        digit.insert(num);  
        return;  
    }  
    for (int i = 0; i < 4; i++) {  
        int nx = x + dx[i];  
        int ny = y + dy[i];  
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {  
        //把六数的序列转化为六位的十进制数以区分彼此(字典序法) 
            dfs(nx, ny, step + 1, num * 10 + grid[nx][ny]);  
        }  
    }  
}  
  
  
int main()  
{  
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            scanf("%d", &grid[i][j]);  
        }  
    }  
      
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            dfs(i, j, 0, grid[i][j]);  
        }  
    }  
     
    printf("%lu\n", digit.size()); //%lu表示无符号长整型，是模板size()的类型
      
    return 0;  
}  
