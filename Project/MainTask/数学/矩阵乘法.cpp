#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline long long read()
{
	long long kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
LL nn,mm,kk;
struct matrix
{
	LL jie[110][110];
	int n,m;
	matrix operator * (const matrix &a)const
	{
		matrix b;b.n=n;b.m=a.m;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=a.m;++j)
		{
			b.jie[i][j]=0;
			for(int k=1;k<=m;++k)
			{
				b.jie[i][j]=((jie[i][k]*a.jie[k][j])+b.jie[i][j]);
			}
		}
		return b;
	}
}t1,t2,t3;
matrix mpow(matrix a,LL b)
{
	if(b==1)return a;
	matrix kk=a;b--;
	while(b)
	{
		if(b&1)kk=kk*a;
		a=a*a;
		b>>=1;
	}
	return kk;
}
int main()
{
	nn=read();mm=read();kk=read();
	t1.n=nn;t1.m=mm;t2.n=mm;t2.m=kk;
	for(int i=1;i<=nn;++i)
	for(int j=1;j<=mm;++j)t1.jie[i][j]=read();
	for(int i=1;i<=mm;++i)
	for(int j=1;j<=kk;++j)t2.jie[i][j]=read();
	t3=t1*t2;
	for(int i=1;i<=nn;++i)
	{
		for(int j=1;j<=kk;++j)cout<<t3.jie[i][j]<<" ";
		cout<<endl;
	}
	
}
