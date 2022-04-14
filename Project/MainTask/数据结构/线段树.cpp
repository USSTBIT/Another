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
const int N=100022;
LL ans[N];int n,m;
struct segment_tree
{
	int l,r;LL dat,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
	#define add(x) tree[x].add
}tree[4*N];
void update(int p)
{
	dat(p)=dat(p*2)+dat(p*2+1);
}
void build(int p,int l,int r)
{
	l(p)=l;r(p)=r;
	if(l==r){dat(p)=ans[l];return;}
	int mid=l+(r-l)/2;
	build(p*2,l,mid);build(p*2+1,mid+1,r);
	update(p);
}
void spread(int p)
{
	if(add(p))
	{
		dat(p*2)+=(r(p*2)-l(p*2)+1)*add(p);
		dat(p*2+1)+=(r(p*2+1)-l(p*2+1)+1)*add(p);
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		add(p)=0;
	}
}
void change(int p,int l,int r,int v)
{
	if(l<=l(p)&&r(p)<=r){dat(p)+=(LL)v*(r(p)-l(p)+1);add(p)+=v;return;}
	spread(p);
	int mid=l(p)+(r(p)-l(p))/2;
	if(l<=mid)change(p*2,l,r,v);
	if(r>mid)change(p*2+1,l,r,v);
	update(p);
}
LL query(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)return dat(p);
	spread(p);
	int mid=l(p)+(r(p)-l(p))/2;
	LL val=0;
	if(l<=mid)
	{
		val+=query(p*2,l,r);
	}
	if(r>mid)
	{
		val+=query(p*2+1,l,r);
	}
	return val;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)ans[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int o,x,y;o=read();x=read();y=read();
		if(o==1)
		{
			LL kk=read();
			change(1,x,y,kk);
		}
		else 
		{
			cout<<query(1,x,y)<<endl;
		}
	}
}
