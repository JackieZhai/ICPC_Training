/*
练习题：Packets_POJ 1017
	及其暴力的贪心。 
	 
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int s1, s2, s3, s4, s5, s6;
    while(scanf("%d%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5, &s6) && s1+s2+s3+s4+s5+s6)
	{
        int packets = 0;
        packets += s6; // 6*6的产品一个装一箱
        
        packets += s5; // 5*5的产品一个装一箱
        s1 = max(0, s1-11*s5); // 剩余空间用1*1的产品尽量填满
        
        packets += s4; // 4*4的产品一个装一箱
        if(s2<5*s4) s1 = max(0, s1-(5*s4-s2)); // 假如2*2的产品填完之后仍然有空隙，则用1*1填满 
        s2 = max(0, s2-5*s4); // 尽量用2*2的产品填满 
        
        packets += (s3+3)/4; // 3*3的产品四个一箱
        s3 %= 4;            // 假如3*3的箱子不是四的倍数个，则先用2*2填充再用1*1填充 
        if(s3==1)
		{
            if(s2<5) s1 = max(0, s1-(27-4*s2));
            else     s1 = max(0, s1-7);
            s2 = max(0, s2-5);
        } 
        else if(s3==2)
		{
            if(s2<3) s1 = max(0, s1-(18-4*s2));
            else     s1 = max(0, s1-6);
            s2 = max(0, s2-3);
        }
        else if(s3==3)
		{
            if(s2<1) s1 = max(0, s1-(9-4*s2));
            else     s1 = max(0, s1-5);
            s2 = max(0, s2-1);    
        }
        
        packets += (s2+8)/9; // 2*2的产品九个一箱
        s2 %= 9;             // 假如2*2的箱子不是九的倍数个，则用1*1填充
        if(s2) s1 = max(0, s1-(36-4*s2)); 
        
        packets += (s1+35)/36; // 1*1的产品三十六个一箱
        
        printf("%d\n", packets); 
    } 
    
    return 0;
}
