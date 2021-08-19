///如果你使用C++或C语言而且准备使用printf输出结果，则你的格式字符串应该写成%I64d以输出long long类型的整数。
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    scanf("%I64d", &n);
    printf("%I64d\n", (1+n)*n/2);



    return 0;
}
