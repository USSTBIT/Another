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
const LL N=2000222;
int a[N];int n,m;
int f[N][30];
void pre_st()
{
	for(int i=1;i<=n;++i)f[i][0]=a[i];
	int t=log2(n)+1;
	for(int j=1;j<t;++j)
	for(int i=1;i<=(n-(1<<j)+1);++i)
	{
		f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
}
int query_st(int l,int r)
{
	int len=(log2(r-l+1));
	return max(f[l][len],f[r-(1<<(len))+1][len]);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	pre_st();
	for(int i=1;i<=m;++i)
	{
		int a,b;a=read();b=read();
		cout<<query_st(a,b)<<endl;
	}
}
