#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
bool f[maxn];
void fun(){
	for(int i=2;i<maxn;++i){
		if(f[i]==false){
			for(int j=2;j*i<maxn;++j)
				f[i*j]=true;
		}
	}
}
vector<int> number;
void findnum(){
	for(int i=2;i<maxn;++i)
		if(f[i]==false)
			number.push_back(i);
}
struct sct{
	int x,cnt;
	sct(int _x,int _cnt):x(_x),cnt(_cnt){}
};
vector<sct> res;
int main(){
	int n,m;
	cin>>n;
    m=n;
	if(n==1){
		cout<<"1=1";
		return 0;
	}
	findnum();
	int sqr=(int)sqrt(1.0*n);
	int index=-1;
	for(int i=0;i<number.size()&&number[i]<=sqr;++i){
		if(n%number[i]==0){
			index++;
			res.push_back(sct(number[i],0));
		}
		while(n%number[i]==0){
			res[index].cnt++;
			n/=number[i];
		}
		if(n==1)break;
	}
	if(n!=1)res.push_back(sct(n,1));
	if(res[0].cnt!=1)
        cout<<m<<"="<<res[0].x<<"^"<<res[0].cnt;
    else
        cout<<m<<"="<<res[0].x;
	for(int i=1;i<res.size();++i){
		if(res[i].cnt>1)
			cout<<"*"<<res[i].x<<"^"<<res[i].cnt;
		else
			cout<<"*"<<res[i].x;
	}
		
	return 0;
}