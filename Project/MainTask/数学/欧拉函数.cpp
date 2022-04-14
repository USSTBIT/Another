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
const int maxn=1e6+50;
int phi[maxn],vis[maxn],su[maxn],co;
void init1()//nlogn 
{
	for(int i=1;i<(maxn-5);++i)phi[i]=i; 
    for(int i=2;i<(maxn-5);++i)
	if(phi[i]==i)  
    for(int j=i;j<maxn-5;j+=i)phi[j]=(phi[j]/i)*(i-1);    
}
void init()//Япад 
{
	co=0;
	phi[1]=1;
	for(int i=2;i<=maxn-16;++i)
	{
		if(!vis[i])
		{
			vis[i]=i;su[++co]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=co;++j)
		{
			if(su[j]>vis[i]||su[j]>(maxn-18)/i)break;
			vis[i*su[j]]=su[j];
			if(i%su[j])phi[i*su[j]]=phi[i]*(su[j]-1);
			else phi[i*su[j]]=phi[i]*(su[j]);
		}
	}
}
int main()
{
	init();
	int T=read();
	while(T--)
	{
		int k=read();
		printf("%d\n",phi[k]);
	}
} 
