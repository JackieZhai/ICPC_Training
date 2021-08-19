/*
	�ݹ���ú���create()�����Ҹ����ֳ����������������� 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
struct node{
    char ch;
    struct node *left,*right;
};

struct node* creat(char *pre,char *in,int len)
{
    if(len==0)
        return NULL;
        
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));    
    head->ch=pre[0];
    
    char *p;
    for(p=in;p != NULL;p++)//ָ���ַ����п�Ϊ������־ 
        if(*p == *pre)
            break;
            
    int k=p-in;
    head->left=creat(pre+1,in,k);
    head->right=creat(pre+k+1,p+1,len-k-1);
    return head; 
}

void post(struct node* head)
{
    if(head == NULL)
        return;
    post(head->left);
    post(head->right);
    printf("%c",head->ch);
}

int main()
{
    char pre[30],in[30];
    struct node *head;
    head = ( struct node *)malloc(sizeof(struct node));
    while(scanf("%s %s",pre,in) != EOF)
    {
        int len=strlen(pre);
        head=creat(pre,in,len);
        
        post(head);//�������
        printf("\n");
    }
    return 0;
}

