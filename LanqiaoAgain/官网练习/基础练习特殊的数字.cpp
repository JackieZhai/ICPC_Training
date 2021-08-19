#include <bits/stdc++.h>
using namespace std;


int main()
{
    for(int k=100; k<1000; k++)
    {
        if((k/100)*(k/100)*(k/100)+(k%100/10)*(k%100/10)*(k%100/10)+(k%10)*(k%10)*(k%10)==k)
            printf("%d\n", k);
    }



    return 0;
}
