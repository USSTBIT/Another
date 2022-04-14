#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
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
LL k[1000222],m[2000222],n;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b){x=1;y=0;return a;}
	LL lin=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return lin;
}
LL mmul(LL a,LL b,LL mod)
{
	LL kk=0;
	while(b)
	{
		if(b&1)kk=(kk+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return kk;
}
LL excrt()
{
	LL x,y,a,b,c,M,ans,g;
	M=m[1];ans=k[1];
	for(int i=2;i<=n;++i)
	{
		a=M;b=m[i];
		c=((k[i]-ans)%b+b)%b;
		g=exgcd(a,b,x,y);
		if(c%g!=0)return -1;
		x=mmul(x,c/g,b/g);
		ans=(ans+M*x);M*=(b/g);
		ans=(ans%M+M)%M;
	}
	return (ans%M+M)%M;
}
int main()
{
	int T=1;
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld",&m[i],&k[i]);
		}
		LL asd=excrt();
		if(asd==-1)printf("Impossible\n");
		else printf("%lld\n",asd);
	}
	
}
