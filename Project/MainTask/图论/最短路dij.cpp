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
const int maxn=124514;
const LL INF=0x3f3f3f3f;
struct zj
{
	LL to,k,b,val;
};
vector<zj>edge[maxn];
#define pii pair<LL,LL>
#define mp(x,y) make_pair(x,y)
LL dis[maxn],l,r,n,m,H;
bool vis[maxn];
LL dij(LL day)
{
	priority_queue<pii,vector<pii>,greater<pii> >Q;
	while(!Q.empty())Q.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;Q.push(mp(0,1));
	while(!Q.empty())
	{
		LL now=Q.top().second;Q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=0;i<edge[now].size();++i)
		{
			LL to,val;
			to=edge[now][i].to;
			val=edge[now][i].k*day+edge[now][i].b;//Ȩֵ 
			if(dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				Q.push(mp(dis[to],to));
			}
		}
	}
	return dis[n];
}

int main()
{
	n=read();m=read();H=read();
	for(int i=1;i<=m;++i)
	{
		LL fr,to,ki,bi;
		fr=read();to=read();ki=read();bi=read();
		edge[fr].push_back((zj){to,ki,bi});
	}
	l=0;r=H;
	LL asd=0;
	while(r-l>5)
	{
		LL mid1,mid2;mid1=(r+l+l)/3;mid2=(r+r+l)/3;
		LL ans1,ans2;ans1=dij(mid1);ans2=dij(mid2);
		if(ans1<=ans2)
		{
			asd=max(asd,ans2);
			l=mid1;
		}
		else
		{
			asd=max(asd,ans1);
			r=mid2;
		}
	}
	for(LL i=max(0ll,l-2);i<=min(H,r+2);++i)
	{
		asd=max(asd,dij(i));
	}
	printf("%lld\n",asd);
}
