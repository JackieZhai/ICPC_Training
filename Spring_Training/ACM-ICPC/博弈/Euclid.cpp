#include <cstdio>
#include <algorithm>
using namespace std;


int a, b;

int main()
{
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        if(a==0 && b==0)
            break;

        bool f=true;
        while(true)
        {
            if(a>b)
                swap(a, b);

            //b��a�ı�����ʱ��ʤ��ȷ��
            if(b%a==0)
                break;

            //��������ɵ����ʤ��ȷ��
            if(b-a>a)
                break;

            //ʤ������
            //������StanӮ��ż����OllieӮ
            b-=a;
            f=!f;
        }

        if(f)
            puts("Stan wins");
        else
            puts("Ollie wins");
    }



    return 0;
}
