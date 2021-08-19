#include <bits/stdc++.h>
using namespace std;


struct Node{
    string fr, lo;
    int nu;
    friend bool operator < (const Node &a, const Node &b)
    {
        if(a.lo==b.lo)
        {
            if(a.fr==b.fr)
                return a.nu>b.nu;
            return a.fr>b.fr;
        }
        return a.lo>b.lo;
    }
    Node(string f, string l, int n):fr(f), lo(l), nu(n){}
};

int N, M;

int main()
{
    ios::sync_with_stdio(false);

    cin>>N;
    while(N--)
    {
        cin>>M;
        priority_queue<Node> que, que2;
        for(int i=0; i<M; i++)
        {
            string buf1, buf2;
            cin>>buf1>>buf2;
            int buf;
            cin>>buf;
            que.push(Node(buf1, buf2, buf));
        }

        while(que.size())
        {

            Node n=que.top();
            que.pop();
            if(que.size())
            {
                Node n2=que.top();
                while(n2.fr==n.fr && n2.lo==n.lo)
                {

                    que.pop();
                    n.nu+=n2.nu;
                    if(que.size())
                        n2=que.top();
                    else
                        break;
                }
            }
            que2.push(n);
        }

        string nowlo="";
        Node n=que2.top();
        while(que2.size())
        {
            nowlo=n.lo;
            cout<<nowlo<<endl;
            while(nowlo==n.lo)
            {

                que2.pop();
                cout<<"   |----"<<n.fr<<"("<<n.nu<<")"<<endl;
                if(que2.size())
                    n=que2.top();
                else
                    break;
            }
        }
        if(N)
            cout<<endl;

    }



    return 0;
}



///原来map在用iterator遍历的时候也是有字典序的
string s1,s2;
int main()
{
    typedef map<string,map<string,int> > mmp;
    typedef map<string,int> mp;
    mmp p;
    int t,n,num,flag = 0;
    cin>>t;
    while(t--){
        p.clear();
        cin>>n;
        while(n--){
            cin>>s2>>s1>>num;
            p[s1][s2]+=num;
       }
       mmp::iterator iter1;
       mp::iterator iter2;
       for(iter1 = p.begin(); iter1!= p.end();iter1++){
            cout<<iter1->first<<endl;
            for(iter2 = iter1->second.begin();iter2 != iter1->second.end();iter2++){
                cout<<"   |----"<<iter2->first<<"("<<iter2->second<<")"<<endl;
            }
       }
       if(t){
        cout<<endl;
       }
    }

    return 0;

}
