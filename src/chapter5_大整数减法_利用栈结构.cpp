#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	if(a.size()<b.size()||(a.size()==b.size()&&a<b)){
		cout<<"-";
		swap(a,b);
	}
	int lena=a.size();
	int lenb=b.size();
	for(int i=0;i<lena-lenb;++i)
		b='0'+b;
	int front=0,v;
	stack<int> s;
	for(int i=lena-1;i>=0;--i){
		v=a[i]-b[i]+front;
		s.push(v>=0?v:v+10);
		front=(v>=0?0:-1);
	}
	while(s.top()==0)s.pop();
	if(s.empty())cout<<"0";
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
}