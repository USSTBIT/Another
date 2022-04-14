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
}const int maxn=200222;
int trie[maxn][33],tot=1;
int cnt[maxn];//记录这个字符串结尾的数目 
void insert(char *str)
{
	int len=strlen(str),p=1;
	for(int i=0;i<len;++i)
	{
		int ch=str[i]-'a';
		if(!trie[p][ch])trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	cnt[p]++;
}
int search(char* str)//查询插入的串里面str的前缀的数量 
{
	int len=strlen(str),p=1,asd=0;
	for(int i=0;i<len;++i)
	{
		p=trie[p][str[i]-'a'];
		asd+=cnt[p];//已经是结尾了，说明是前缀 
		if(p==0)break;
	}
	return asd;
}
char ss[maxn],s1[maxn];
int main()
{
	int n,m;n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ss);
		insert(ss);
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%s",s1);
		printf("%d\n",search(s1));
	}
}
