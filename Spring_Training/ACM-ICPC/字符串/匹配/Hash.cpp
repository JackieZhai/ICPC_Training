///Rabin-Karp算法，一般不检查哈希值是否发生冲突

#include <bits/stdc++.h>
using namespace std;



typedef unsigned long long ull;
const ull B=100000007; //哈希的基数

//a是否在b中出现
bool contain(string a, string b)
{
    int al=a.length(), bl=b.length();
    if(al>bl)
        return false;

    //计算B的al次方
    ull t=1;
    for(int i=0; i<al; i++)
        t*=B;

    //计算a和b长度为al的前缀对应的哈希值
    ull ah=0, bh=0;
    for(int i=0; i<al; i++)
        ah=ah*B+a[i];
    for(int i=0; i<al; i++)
        bh=bh*B+b[i];

    //对b不断后移一位，更新哈希值并判断
    for(int i=0; i+al<=bl; i++)
    {
        if(ah==bh)
            return true; //b从位置i开始长度为al的字符串子串等于a
        if(i+al<bl)
            bh=bh*B+b[i+al]-b[i]*t;
    }
    return false;
}





int main()
{



    return 0;
}
