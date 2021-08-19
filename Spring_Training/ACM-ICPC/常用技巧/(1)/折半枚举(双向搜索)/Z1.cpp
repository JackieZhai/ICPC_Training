/**
���⣺4 Values whose Sum is 0_POJ 2785

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=4007;

int n;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

int CD[MAX_N * MAX_N]; //C��D�����ֵ���Ϸ���



int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);


    //ö�ٴ�C��D��ȡ�����ֵ����з���
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            CD[i*n+j]=C[i]+D[j];
        }
    }
    sort(CD, CD+n*n);

    long long res=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int cd=-(A[i]+B[j]);
            //ȡ��C��D�к�Ϊcd�Ĳ���
            res+=upper_bound(CD, CD+n*n, cd)-lower_bound(CD, CD+n*n, cd);
        }
    }

    printf("%lld\n", res);

    return 0;
}
