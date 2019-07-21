#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}road[100005];
bool cmp(const node &one,const node &two){
	return one.w<two.w;
}
int f[100005];
typedef long long ll;
int getf(int x){
	if(x==f[x])return f[x];
	f[x]=getf(f[x]);
	return f[x];
}
bool merge(int x,int y){
	int t1=getf(x);
	int t2=getf(y);
	if(t1!=t2){
		f[t2]=t1;
		return true;
	}
	return false;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
		scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w); 
	sort(road,road+m,cmp);
	for(int i=1;i<=n;++i)
		f[i]=i;
	ll ans=0;
	int cnt=0;
	for(int i=0;i<m;++i){
		if(merge(road[i].u,road[i].v)){
			ans+=road[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	printf("%lld",ans);
	return 0;
}
