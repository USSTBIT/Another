#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read()
{
	LL kk=0,f=1;char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
LL qc(LL a,LL b,LL mod)
{
	LL kk=0;
	while(b)
	{
		if(b&1)kk=(kk+a)%mod;
		b>>=1;a=(a+a)%mod;
	}
	return kk;
}
LL qp(LL a,LL b,LL mod)
{
	LL kk=1;
	while(b)
	{
		if(b&1)kk=qc(kk,a,mod);
		b>>=1;
		a=qc(a,a,mod);
	}
	return kk;
}
int main()
{
	LL a=read(),b=read(),c=read();
	printf("%lld^%lld mod %lld=",a,b,c);
	LL jie=qp(a,b,c);
	printf("%lld\n",jie);
}
