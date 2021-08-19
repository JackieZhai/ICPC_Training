#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000+10;

struct Node
{
    int value;
    Node *lson, *rson;
    Node():lson(NULL),rson(NULL){}
}*root;

int n;
int s[maxn];
vector<int> ans; //�����¼���������Ԫ�أ���Ϊ�ں���������ʱ���ܿ������Ŀո�

//�ж� kindΪtrue�ж�ԭ����Ϊfalse�жϾ���
bool test(bool kind, int L, int R)
{
    if(L >= R)
        return true;
    int i;
    for(i = L+1; i <= R; i++)
    {
        if(kind)
        {
            if(s[L] <= s[i])
                break;      //�� i-1 ΪֹΪ������
        }
        else
        {
            if(s[L] > s[i])
                break;
        }
    }
    bool flag = true;
    for(int j = i; j <= R; j++)
    {
        if(kind)
        {
            if(s[j] < s[L])
                flag = false;  //����������С�ڸ����ֵ��ֱ�ӷ��� false
        }
        else
        {
            if(s[j] >= s[L])
                flag = false;
        }

    }
    if(flag)
        return test(kind, L+1, i-1) && test(kind, i, R); //һֱ�ݹ������ȥ

    else
        return false;
}


Node* create(bool kind, int L, int R)
{
    if(L > R)
        return NULL;
    int i;
    for(i = L+1; i <= R; i++)
    {
        if(kind)
        {
            if(s[L] <= s[i])
                break;   //��i-1ΪֹΪ������
        }
        else
        {
            if(s[L] > s[i])
                break;
        }
    }
    Node *p = new Node();
    p->value = s[L];
    p->lson = create(kind, L+1, i-1); //�ݹ齨��������
    p->rson = create(kind, i, R);  //�ݹ齨��������

    return p;
}

void postOrderTraverse(Node *p)
{
    if(p)
    {
        postOrderTraverse(p->lson);
        postOrderTraverse(p->rson);
        ans.push_back(p->value);
    }
}

void Print()
{
    postOrderTraverse(root);
    int len = ans.size();
    for(int i = 0; i < len-1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[len-1]);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);

    int flag = 0;
    if(test(true, 0, n-1))
    {
        flag = 1;
        root = create(true, 0, n-1);
    }
    else if(test(false, 0, n-1))
    {
        flag = 2;
        root = create(false, 0, n-1);
    }
    if(flag != 0)
    {
        puts("YES");
        Print();
    }
    else
        puts("NO");

    return 0;
}
