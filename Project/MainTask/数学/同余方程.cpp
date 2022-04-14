#include<bits/stdc++.h>
#define NMAX 0x7fffffff
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
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0){x=1;y=0;return a;}
	LL k=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return k;
}
bool tyfc(LL a,LL b,LL c)//求ax+by=c 
{
	LL x,y;
	LL gcdn=exgcd(a,b,x,y);
	if(c%gcdn)return 0;
	x*=(c/gcdn);y*=(c/gcdn);//得到 初始特解（可能含负数） 
	LL mod=b/gcdn;//通解中每次x增加的量 
	x=(x%mod+mod)%mod;//得到一号解（x最小的情况） 
	y=(c-a*x)/b;
	if(y<0)return 0;
	while(1)//得到各个解 
	{
		y=y-a/gcdn;
		if(y<0)break;
		x=x+b/gcdn;
	}
	return 1;
}
int main()
{
	LL n;
	while(n=read())
	{
	    LL a,b;a=read();b=read();
		if(!tyfc(a,b,n))printf("failed\n");
	}
	return 0;
} 
