///ʵ��������������û���ر�˵�������붼�ǰ�����������С�
#include <bits/stdc++.h>
using namespace std;


double PI=acos(-1);


int main()
{
    int r;
    scanf("%d", &r);
    double s=PI*r*r;
    s=floor((s*10000000)+0.5)/10000000;

    printf("%.7lf\n", s);

    return 0;
}
