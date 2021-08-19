///Rabin-Karp�㷨��һ�㲻����ϣֵ�Ƿ�����ͻ

#include <bits/stdc++.h>
using namespace std;



typedef unsigned long long ull;
const ull B=100000007; //��ϣ�Ļ���

//a�Ƿ���b�г���
bool contain(string a, string b)
{
    int al=a.length(), bl=b.length();
    if(al>bl)
        return false;

    //����B��al�η�
    ull t=1;
    for(int i=0; i<al; i++)
        t*=B;

    //����a��b����Ϊal��ǰ׺��Ӧ�Ĺ�ϣֵ
    ull ah=0, bh=0;
    for(int i=0; i<al; i++)
        ah=ah*B+a[i];
    for(int i=0; i<al; i++)
        bh=bh*B+b[i];

    //��b���Ϻ���һλ�����¹�ϣֵ���ж�
    for(int i=0; i+al<=bl; i++)
    {
        if(ah==bh)
            return true; //b��λ��i��ʼ����Ϊal���ַ����Ӵ�����a
        if(i+al<bl)
            bh=bh*B+b[i+al]-b[i]*t;
    }
    return false;
}





int main()
{



    return 0;
}
