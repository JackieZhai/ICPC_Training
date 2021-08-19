
//ST START
 
const int MAX_N=1<<17;
const int INT_MAX=0x3f3f3f3f;

//�����߶�����ȫ������
int n, dat[2*MAX_N-1];

//��ʼ��
void init(int n_)
{
	//Ϊ�˼��������Ԫ�صĸ�������2����
	n=1;
	while(n<n_)
		n*=2;
	
	//�����е�ֵ����ΪINT_MAX
	for(int i=0; i<2*n-1; i++)
		dat[i]=INT_MAX; 
}

//�ѵ�k��ֵ(0-indexed)����Ϊa
void update(int k, int a)
{
	//Ҷ�ӽ��
	k+=n-1;
	dat[k]=a;
	//���ϸ���
	while(k>0)
	{
		k=(k-1)/2;
		dat[k]=min(dat[k*2+1], dat[k*2+2]);
	}
}

//��[a, b)����Сֵ
//����Ĳ�����Ϊ�˼�����������������
//k�ǽ��ı�ţ�l��r��ʾ�������Ӧ����[l, r)����
//���ⲿ����ʱ�� ��query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r)
{
	//���[a, b)��{l, r)���ཻ���򷵻�INT_MAX
	if(r<=a||b<=l)
		return INT_MAX;
	
	//���[a, b)��ȫ������[l, r)���򷵻ص�ǰ����ֵ
	if(a<=l&&r<=b)
		return dat[k];
	else
	{
		int vl=query(a, b, k*2+1, l, (l+r)/2);
		int vr=query(a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
}

//ST END 
