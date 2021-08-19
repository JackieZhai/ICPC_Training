#include <bits/stdc++.h>
using namespace std;

int dx[]={0,0,0,1,1,1,-1,-1,-1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};  
const int LMT=8;  
int tag = 0;  
char gra[LMT][LMT];  
void dfs(int i,int j,int t)  
{
	//带有剪枝的DFS 
    if(tag||t>=LMT||i<=t)  
    {  
        tag=1;  
        return;  
    }  
    int ii,jj;  
    for(int x=0;x<9;x++)  
    {  
        ii=i+dx[x];jj=j+dy[x];  
        if(ii>=0&&ii<LMT&&jj>=0&&jj<LMT)  
        {   
        	//此时的雕像和下一步的雕像位置都不能走（体会-t的作用！） 
            if(gra[ii-t][jj]!='S'&&(ii<=t||gra[ii-1-t][jj]!='S'))  
            dfs(ii,jj,t+1);  
            if(tag)return;  
        }  
    }  
}  
int main()  
{  
	for(int i=0;i<LMT;i++)
		scanf("%s",gra[i]);  
    dfs(LMT-1,0,0);
    if(tag)
		puts("WIN");  
    else
		puts("LOSE");  
    return 0;  
}  
