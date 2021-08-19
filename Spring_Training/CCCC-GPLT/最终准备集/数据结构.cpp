///���ݽṹ���

///���鼯
int par[MAX_N];//����
int ran[MAX_N];//���ĸ߶�
//��ʼ��n��Ԫ��
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		ran[i]=0;
	}
}
//��ѯ���ĸ�
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}
//�ϲ�x��y�����ļ���
void unite(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	if(ran[x]<ran[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ran[x]==ran[y])
			ran[x]++;
	}
}
//�ж�x��y�Ƿ�����ͬһ������
bool same(int x, int y)
{
	return find(x)==find(y);
}


///���ȶ���
priority_queue<int, vector<int>, greater<int> > que;
//pairҲ������ô��


///����
//ע�ⷵ�ص���ָ��
upper_bound(a, a+n, k) - lower_bound(a, a+n, k) //a�е���k�ĸ���
//�ٶ�һ�����ж��Ƿ����
bool C()
{

}
void solve()
{
    int lb=0, ub=INF;

    for(int i=0; i<100; i++)
    while(ub-lb>1)
    {
        int mid=(lb+ub)/2;
        if(C(mid))
            lb=mid;
        else
            ub=mid;
    }

    printf("%d\n", lb);
}


///������
Template::iterator ite;
//ע��set��map���е������ǰ������<�����������


///set(multiset)
s.begin()       //  ����ָ���һ��Ԫ�صĵ�����
s.clear()       //  �������Ԫ��
s.count()       //  ����ĳ��ֵԪ�صĸ���
s.empty()       //  �������Ϊ�գ�����true(�棩
s.end()         //  ����ָ�����һ��Ԫ��֮��ĵ��������������һ��Ԫ��
s.erase()       //  ɾ�������е�Ԫ��
s.find()        //  ����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����
s.insert()      //  �ڼ����в���Ԫ��
s.lower_bound() //  ����ָ����ڣ�����ڣ�ĳֵ�ĵ�һ��Ԫ�صĵ�����
s.size()        //  ������Ԫ�ص���Ŀ
s.upper_bound() //  ���ش���ĳ��ֵԪ�صĵ�����


///map(multimap)
/*  ��map�в���Ԫ��  */
m[key] = value; //  [key]������map������ɫ�Ĳ���,�����map�д��ڼ�ֵΪkey��Ԫ�ض�, �򷵻ظ�Ԫ�ضԵ�ֵ�򲿷�,���򽫻ᴴ��һ����ֵΪkey��Ԫ�ض�,ֵ��ΪĬ��ֵ�����Կ����øò�����map�в���Ԫ�ضԻ��޸��Ѿ����ڵ�Ԫ�ضԵ�ֵ�򲿷֡�
m.insert(make_pair(key, value));    //  Ҳ����ֱ�ӵ���insert��������Ԫ�ض�,insert�����᷵��һ��pair,��map��û����key��ƥ��ļ�ֵʱ,��first��ָ�����Ԫ�ضԵĵ�����,��secondΪtrue;��map���Ѿ�������key��ȵļ�ֵʱ,��first��ָ���Ԫ�ضԵĵ�����,secondΪfalse��

/*  ����Ԫ��  */
int i = m[key]; //  Ҫע�����,����ü�ֵ��ƥ���Ԫ�ضԲ�����ʱ,�ᴴ����ֵΪkey������һ��Ԫ��������ʱ��m[key]=0����Ԫ�ضԡ�
map<string, int>::iterator it = m.find(key);    //  ���map�д�����key��ƥ��ļ�ֵʱ,find����������ָ���Ԫ�ضԵĵ�����,����,���صĵ���������map��end()(�μ�vector���ᵽ��begin()��end()����)��

/*  ɾ��Ԫ��  */
m.erase(key);   //  ɾ����ָ��key��ֵ��ƥ���Ԫ�ض�,�����ر�ɾ����Ԫ�صĸ�����
m.erase(it);    //  ɾ���ɵ�����it��ָ����Ԫ�ض�,������ָ����һ��Ԫ�ضԵĵ�������

/*  ��������  */
m.size();       //  ����Ԫ�ظ���
m.empty();      //  �ж��Ƿ�Ϊ��
m.clear();      //  �������Ԫ��

///vector
s[i]                //  ֱ�����±귽ʽ���������е�Ԫ��
s.front()           //  ������Ԫ��
s.back()            //  ����βԪ��
s.push_back(x)      //  ���β����Ԫ��x
s.size()            //  ���ر�
s.empty()           //  ��Ϊ��ʱ�������棬���򷵻ؼ�
s.pop_back()        //  ɾ����βԪ��
s.begin()           //  ����ָ����Ԫ�ص������ȡ������
s.end()             //  ����ָ��βԪ�ص���һ��λ�õ������ȡ������
reverse(s.begin(), s.end()); //  ��ת
s.insert(it, val)   //  �������itָ���Ԫ��ǰ������Ԫ��val
s.insert(it, n, val)//  �������itָ���Ԫ��ǰ����n����Ԫ��val
s.insert(it, first, last)
//  ���ɵ�����first��last��ָ��������[first, last)���뵽������itָ���Ԫ��ǰ��
s.erase(it)         //  ɾ���ɵ�����it��ָ���Ԫ��
s.erase(first, last)//  ɾ���ɵ�����first��last��ָ��������[first, last)
s.clear()           //  ɾ�������е�����Ԫ��
s.swap(v)           //  ��s����һ��vector������н���
