#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double area[5];
const double PI=acos(-1.0);
double n,m,t,c;//n�У�m�У�tС����ı߳���cӲ��ֱ��

int main()
{
    int cas;cin>>cas;
    for(int i=1;i<=cas;i++)
    {
        cin>>n>>m>>t>>c;
        area[0]=t*t*n*m;//�����
        double d11=(t-c/2)*(t-c/2)*4;//���ϵ��ĸ�
        double d12=(t-c/2)*(t-c)*(n+m-4)*2;//���һȦ��ȥ���ϵ�
        double d13=(t-c)*(t-c)*(n*m-(2*(n+m)-4));//��ȥһȦ�����
        area[1]=d11+d12+d13;

        double d21=c*(t-c/2)*((m-1)*2+(n-1)*2);//�ڱ��ϵ�
        double d22=c*(t-c)*((m-1)*n+(n-1)*m-(m-1)*2-(n-1)*2);//�����ϵ�
        area[2]=d21+d22;

        area[3]=(c*c-PI*(c/2)*(c/2))*(n-1)*(m-1);

        area[4]=PI*c*c/4*(n-1)*(m-1);

        cout<<"Case "<<i<<":"<<endl;
        for(int i=1;i<=4;i++)
        {
            cout<<"Probability of covering "<<i;
            if(i==1)
                cout<<" tile  = ";
            else
                cout<<" tiles = ";
            cout<<setiosflags(ios::fixed)<<setprecision(4)<<area[i]/area[0]*100<<"%"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
