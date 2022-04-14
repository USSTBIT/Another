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
LL mod=1000000007;
void exgcd(LL a,LL b,LL &x,LL &y)
{
   if(!b){x=1;y=0;return;}
   exgcd(b,a%b,y,x);
   y-=(a/b)*x;
}
LL ni(LL a)
{
   LL nia,y;
   exgcd(a,mod,nia,y);
   return (nia%mod+mod)%mod;
}
int main()
{
    
}
