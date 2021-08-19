/*
��ϰ�⣺Hopscotch_POJ 3050

��������dfs�ڷ��������ߣ����ô��ε���ʽ��¼��������������(����ֻ����λ)�� 
*/
#include <cstdio>  
#include <set>  
using namespace std;  
  
int grid[6][6];  
int dx[4] = {-1, 0, 1, 0};  
int dy[4] = {0, -1, 0, 1};  

//����set(������multiset)�����ظ����� 
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
        //������������ת��Ϊ��λ��ʮ�����������ֱ˴�(�ֵ���) 
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
     
    printf("%lu\n", digit.size()); //%lu��ʾ�޷��ų����ͣ���ģ��size()������
      
    return 0;  
}  
