/*
º”¡∑Ã‚£∫Permute Digits_Codeforces 915C
	
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x=0,y=0;
	string s1,s2;
	cin>>s1>>s2;
	x=s1.length();
	y=s2.length();
	
	sort(s1.begin(),s1.end());
	
	if(x<y)
	{
		reverse(s1.begin(),s1.end());
		cout<<s1<<endl;
		return 0;
	}
	
	string temp;
	for(int i=0;i<x;i++)
		for(int j=x-1;j>i;j--)
		{
			temp=s1;
	  		swap(s1[i],s1[j]);
	  		sort(s1.begin()+i+1,s1.end());
	  		if(s1.compare(s2)>0)
			{
	  			s1=temp;
	  		}
		    else
			{
		  		break;
			}
	    }
	cout<<s1<<endl;
	  
	return 0; 
}
