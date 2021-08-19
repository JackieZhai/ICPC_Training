/*
加练题：QAQs_Codeforces 894A
	前缀和 
*/
#include <bits/stdc++.h>
using namespace std;

#define LL long long 
#define maxn 200 
char str[maxn] ; 
int sum[maxn] ; 

int main(){
    
    while(~scanf(" %s" , str )){
        memset(sum , 0 , sizeof(sum)) ; 
        int num = 0 ; 
        int len = strlen(str) ; 
        for(int i=0 ; i<len ; i++){
            if(str[i] =='Q'){
                num ++ ; 
            }
            
            sum[i] = num ; 
        }
        LL result = 0 ; 
        for(int i=0 ; i<len ; i++){
            if(str[i] =='A')
            result += sum[i] * (sum[len - 1]-sum[i]) ; 
        }
        
        printf("%I64d\n" , result) ; 
    }
    
    return 0 ;
}
