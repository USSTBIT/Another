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
struct zj
{
	int x,y,z;
}edge[10001110],ans[3000];int co=0,cn=0;
bool operator <(zj a,zj b){return a.z<b.z;}
int fa[3000];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int k=read();
			if(i>=j)continue;
			edge[++co].z=k;edge[co].x=i;edge[co].y=j;//加边 ，从邻接矩阵转化 
		}
	}
	sort(edge+1,edge+1+co);
	for(int i=1;i<=n;++i)fa[i]=i;
	LL asd=0;
	for(int i=1;i<=co;++i)
	{
		int x=find(edge[i].x),y=find(edge[i].y);
		if(x==y)continue;
		fa[x]=y;
		asd+=edge[i].z;//最小边权和 
		ans[++cn]=edge[i];//到底连了什么边 
	}
	for(int i=1;i<=cn;++i)
	{
		cout<<ans[i].x<<" "<<ans[i].y<<endl;
	}
	cout<<asd<<endl;
}
