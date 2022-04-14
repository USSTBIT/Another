#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii;
inline long long read()
{
	long long kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
vector<pii> edge[10005*101];
int n,m,k,st,en;bool vis[10005*101];LL dis[10005*101];
const LL maxL=0x3f3f3f3f3f3f3f3fll;
LL dij()
{
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(make_pair(0ll,st));
    dis[st]=0;
    while(!Q.empty())
    {
        int now=Q.top().second;Q.pop();
        if(vis[now])continue;
        if(now%n==en)return dis[now];
        vis[now]=1;
        for(int i=0;i<edge[now].size();++i)
		{
			int to,wei;to=edge[now][i].second;wei=edge[now][i].first;
			if(dis[to]>dis[now]+wei)
			{
				dis[to]=dis[now]+wei;
				Q.push(make_pair(dis[to],to));vis[to]=0;
			}
		}
    }
    return maxL;
}
void doit()
{
	n=read();m=read();k=read();
		for(int i=0;i<=n*(k+1);++i)
		{
			edge[i].clear();dis[i]=maxL;vis[i]=0;
		}
		for(int i=1;i<=m;++i)
		{
			int a,b,w;a=read();b=read();w=read();a--;b--;
			for(int j=0;j<=k;++j)
			{
				edge[a+j*n].push_back(make_pair(w,b+j*n));
                edge[b+j*n].push_back(make_pair(w,a+j*n));
			}
			int mi=0x3f3f3f3f,li=w;
            for(int j=2;j*j<=li;++j)
            if(li%j==0)
            {
                mi=min(mi,2*j+w/j);
                while(li%j==0)li/=j;
            }
            if(li>1)mi=min(mi,2*li+w/li);
            if(mi<w)
            for(int j=0;j<k;++j)
            {
            	edge[a+j*n].push_back(make_pair(mi,b+n*(j+1)));
            	edge[b+j*n].push_back(make_pair(mi,a+n*(j+1)));
			}
		}
		st=read();en=read();
		st--;en--;
		LL asd=dij();
		if(asd==maxL)printf("-1\n");
		else printf("%lld\n",asd);
}
int main()
{
	int T=read();
	while(T--)
	{
		doit();
	}
	return 0;
}
