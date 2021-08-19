/**
练习题：Calendar Game_POJ 1082
    不管是月份加一，还是日期加一，都改变了奇偶性，只有两个特殊日期9月30日，和11月30日例外。
    那么目标日期是11月4日，为奇数。初始日期如果为偶数的话，先者必胜。
    可以大致看到其实胜负和年份是没有关系的说，年份影响的只是2月是否存在第29天……而29是必败点，28为必胜……
    必胜点:月份+日期 == 偶数 （除去两个例外）
*/

#include<stdio.h>

int main()
{
    int T;
    int yy,mm,dd;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&yy,&mm,&dd);

        if((mm+dd)%2==0)
            printf("YES\n");
        else if(dd==30&&(mm==11||mm==9))
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
