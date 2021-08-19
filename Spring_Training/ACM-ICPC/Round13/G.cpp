#include <iostream>
#include <cstdio>
using namespace std;

char a[1000010];
int nex[1000010];
int n;
void GetNext()    //���a���е�next����
{
    int i=0,k=-1;
    nex[0] = -1;
    while(i<n){
        if(k==-1){
            nex[i+1] = 0;
            i++;k++;
        }
        else if(a[i]==a[k]){
            nex[i+1] = k+1;
            i++;k++;
        }
        else
            k = nex[k];
    }
}

void DisRes(int num)
{
    int j;
    printf("Test case #%d\n",num);
    for(int i=0;i<=n;i++){
        if(nex[i]==-1 || nex[i]==0)   //next[i]��-1��0�ĺ��ԣ�˵��֮ǰû��������ǰ׺
            continue;
        j = i - nex[i];
        if(i%j==0)  //��������˵������������ǰ׺
            printf("%d %d\n",i,i/j);    //������ǰ׺�ĳ��Ⱥ�������
    }
    printf("\n");
}


int main()
{
    int num = 0;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%s",a);
        GetNext();  //���next[]����
        DisRes(++num);  //������
    }
    return 0;
}
