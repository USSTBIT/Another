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
int head[10086],cnt=-1;
struct edges
{
	int to,we,next;
}edge[10086];
void addedge(int from,int to,int weigth)
{
	edge[from].to=to;
	edge[from].we=weigth;
	edge[from].next=head[from];
	head[from]=++cnt;
}
void deledge(int from,int to)
{
	int per=0;
	for(int i=head[from];i;i=edge[i].next)
	{
		if(edge[i].to==to)
		{
			if(i==head[from])head[from]=edge[i].next;
			else edge[per].next=edge[i].next;
			return;
		}
		per=i;
	}
}
int main()
{
	
}
