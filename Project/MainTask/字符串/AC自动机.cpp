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
}const int maxn=1000222;
struct TRIE
{
	int son[33],fail,cnt;
	void clear()
	{
		for(int i=0;i<26;++i)son[i]=0;
		fail=0;cnt=0;
	}
}trie[maxn];
int pos=1;
void insert_trie(char *str)
{
	int now=1,len=strlen(str);
	for(int i=0;i<len;++i)
	{
		int ch=str[i]-'a';
		if(!trie[now].son[ch])trie[now].son[ch]=++pos;
		now=trie[now].son[ch];
	}
	trie[now].cnt++;
}
void getfail()
{
	for(int i=0;i<26;++i)trie[0].son[i]=1;
	queue<int>Q;
	Q.push(1);trie[1].fail=0;
	while(!Q.empty())
	{
		int now=Q.front();Q.pop();
		for(int i=0;i<26;++i)
		{
			int to=trie[now].son[i];
			int fafail=trie[now].fail;
			if(!to)
			{
				trie[now].son[i]=trie[fafail].son[i];
				continue;
			}
			trie[to].fail=trie[fafail].son[i];
			Q.push(to);
		}
	}
}
int query_trie(char *str)
{
	int len=strlen(str),fr,to,asd=0;
	fr=1;
	for(int i=0;i<len;++i)
	{
		int ch=str[i]-'a';
		to=trie[fr].son[ch];
		while(to>1&&trie[to].cnt!=-1)
		{
			asd+=trie[to].cnt;
			trie[to].cnt=-1;
			to=trie[to].fail;
		}
		fr=trie[fr].son[ch];
	}
	return asd;
}
char ss[maxn];
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",ss);
		insert_trie(ss);
	}
	getfail();
	scanf("%s",ss);
	printf("%d\n",query_trie(ss));
}
