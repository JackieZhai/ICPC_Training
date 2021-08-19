#include <iostream>
using namespace std;

int A;
bool vis[1007][1007];
int I, J;
int out[77][2];
int e;

int main()
{
    int T;
    cin>>T;
    while(cin>>A)
    {
        if(A%3==0)
            e=A/3;
        else
            e=A/3+1;
        for(int i=0;  i<e; i++)
        {
            out[i][0]=i+2;
            out[i][1]=2;
        }
        for(int i=0; i<1007; i++)
            for(int j=0; j<1007; j++)
                vis[i][j]=false;
        int s=0;
        do{
            for(int i=s; i<e; i++)
            {
                int x=out[i][0], y=out[i][1];
                if(!(vis[x][y]&&vis[x+1][y]&&vis[x][y+1]&&vis[x+1][y+1]&&vis[x-1][y]&&vis[x][y-1]&&vis[x-1][y-1]&&vis[x+1][y-1]&&vis[x-1][y+1]))
                {
                    cout<<x<<" "<<y<<endl;
                    break;
                }
            }
            cin>>I>>J;
            vis[I][J]=true;
            s++;
            if(s>e)
                s-=e;
        }while(!(I==0 && J==0));

    }




    return 0;
}



