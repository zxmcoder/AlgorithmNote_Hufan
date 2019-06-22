//ans[i+j]=a[i]*b[j]
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],ans[maxn*2];
//首先要将字符串倒着存储入整形数组，也就是字符串的下标最后一位存到0位置 
//这样，整形数组的下标低位存储的是数字的低位，正好合适
//然后再利用公式，再化解进位，需要注意的是，ans的存储方式和a,b一致 
//最后删除前导0输出 
void mul(string s1,string s2){
	int cnt=0;
	for(int i=s1.size()-1;i>=0;--i)
		a[cnt++]=s1[i]-'0';
	cnt=0;
	for(int i=s2.size()-1;i>=0;--i)
		b[cnt++]=s2[i]-'0';
	for(int i=0;i<s1.size();++i)
		for(int j=0;j<s2.size();++j)
			ans[i+j]+=a[i]*b[j];
	for(int i=0;i<maxn*2;++i){
		if(ans[i]>=10){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10; 
		}
	}
	int i;
	for(i=maxn*2-1;i>=0;--i)
		if(ans[i]!=0)
			break;
	for(;i>=0;--i)
		cout<<ans[i];
}

int main(){
	string a,b;
	cin>>a>>b;
	mul(a,b);
	return 0;
}