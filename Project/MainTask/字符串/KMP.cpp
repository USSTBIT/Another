#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read()
{
	LL kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
char s1[1000222],s2[1000222];int len1,len2;int co=0;
int mnext[1000222];
void cnext()
{
	mnext[0]=-1;int j=0;
	for(int i=1;i<len2;++i)
	{
		j=mnext[i-1];while(j>-1&&s2[j+1]!=s2[i])j=mnext[j];
		if(s2[j+1]==s2[i])mnext[i]=j+1;
		else mnext[i]=-1;
	}
}
void KMP()
{
	int i=0,j=-1;
	cnext();
	for(;i<len1;++i)
	{
		while(j>-1&&s2[j+1]!=s1[i])j=mnext[j];
		if(s2[j+1]==s1[i])j++;
		if(j+1==len2)
		{
			co++;j=mnext[j];
		}
	}
}
int main()
{
	cin>>s1>>s2;
	len1=strlen(s1);len2=strlen(s2);
	KMP();
	cout<<co;
}
