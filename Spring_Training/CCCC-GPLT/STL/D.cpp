#include <bits/stdc++.h>
using namespace std;

///ע�����set��map��������STL�Ķ��ֲ��ҵ�Ӧ��

int n;
multiset<int> ms;
multiset<int>::iterator it;
char re[7];

int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        ms.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%s", re);
            if(strcmp(re, "Push")==0)
            {
                int p;
                scanf("%d", &p);
                ms.insert(p);
            }
            else
            {
                int q;
                scanf("%d", &q);
                it=ms.upper_bound(q);
                if(it==ms.begin()) //����Ԫ�صĴ�Ӧ����begin()��
                    printf("No Element!\n");
                else
                {
                    it--;
                    printf("%d\n", *it);
                    ms.erase(it);
                }



            }
        }

        printf("\n");


    }



    return 0;
}
