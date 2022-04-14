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
void outLL(LL x)
{
	if(x<0){x=~x+1;putchar('-');}
	if(x>9)outLL(x/10);
	putchar(char(x%10+'0'));
}const int maxn=100055;
const LL INF=1e9+7;
LL a[maxn],b[maxn],n,k;
bool check(double L)
{
	vector<double>V;
	for(int i=1;i<=n;++i)V.push_back((double)((double)a[i]-L*b[i]));
	sort(V.begin(),V.end(),greater<double>());
	double asd=0;
	for(int i=0;i<k;++i)asd+=V[i];
	if(asd>1e-8)return 1;
	return 0;
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
		{
			b[i]=read();a[i]=read();
		}
		double l,r;l=0;r=1e5;
		while(abs(r-l)>1e-4)
		{
			double mid=(l+r)/2.0;
			if(check(mid))l=mid;
			else r=mid;
		}
		printf("%.2lf\n",l);
	}
}
