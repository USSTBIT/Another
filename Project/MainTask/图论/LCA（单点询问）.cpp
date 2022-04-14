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
const int maxn=1000111;
LL node[maxn],a[maxn],n;
vector<LL>edge[maxn];
void add(LL a,LL b)
{
	edge[a].push_back(b);
	edge[b].push_back(a);
}
void dfs1(LL now,LL fa)
{
	for(int i=0;i<edge[now].size();++i)
	{
		LL to=edge[now][i];
		if(to==fa)continue;
		node[to]=node[now]^a[to];
		dfs1(to,now);
	}
}
//lca
LL fun[maxn][22],de[maxn];
void dfsLCA(LL now,LL fa)
{
	fun[now][0]=fa;de[now]=de[fa]+1;
	for(LL i=1;i<=19;++i)
	fun[now][i]=fun[fun[now][i-1]][i-1];
	for(LL i=0;i<edge[now].size();++i)
	{
		LL to=edge[now][i];
		if(to==fa)continue;
		dfsLCA(to,now);
	}
}
LL lca(LL x,LL y)
{
	if(de[x]>de[y])swap(x,y);
	for(LL i=19;i>=0;--i)
	if(de[fun[y][i]]>=de[x])y=fun[y][i];
	if(x==y)return x;
	for(LL i=19;i>=0;--i)
	if(fun[x][i]!=fun[y][i])
	{
		x=fun[x][i];y=fun[y][i];
	}
	return fun[x][0];
}
//lca
int main()
{
	n=read();
	for(LL i=1;i<=n;++i)a[i]=read();
	for(LL i=1;i<n;++i)add(read(),read());
	node[1]=a[1];
	dfs1(1,0);dfsLCA(1,0);
	LL q=read();
	while(q--)
	{
		LL u,v;u=read();v=read();
		LL fat=lca(u,v);
		printf("%lld\n",node[u]^node[v]^a[fat]);
	}
}
