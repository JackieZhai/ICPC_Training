/*
�����⣺A Twisty Movement_Codeforces 933A 
	���������dp��⣬�����и��򵥵��󷨣� 
	�������ת��Ϊ������11...22...11...22...������ȣ� 
	���������ĸ����ֵ���󳤶ȡ� 
*/
#include <bits/stdc++.h>
using namespace std;

int ma1, ma2, ma3, ma4, x, n;

int main() 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
	{
        scanf("%d", &x);
        if (1 == x)
		{
            ++ma1;
            ma3 = max(ma3, ma2) + 1;
        } 
		else 
		{
            ma2 = max(ma1, ma2) + 1;
            ma4 = max(ma4, ma3) + 1;
        }
    }
    printf("%d\n", max(ma3, ma4));
    
    return 0;
}
