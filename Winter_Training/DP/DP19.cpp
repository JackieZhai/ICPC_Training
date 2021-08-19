/*
加练题：A Twisty Movement_Codeforces 933A 
	此题可以用dp求解，不过有更简单的求法： 
	题意可以转化为求子列11...22...11...22...的最长长度， 
	定义上述四个部分的最大长度。 
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
