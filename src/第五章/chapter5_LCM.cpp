//如何求一系列数字的最小公倍数?
//先考虑一下暴力求解
//求LCM记住先除法再乘法
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int m,res,tmp;
	while(n--){
		scanf("%d%d",&m,&res);
		for(int i=1;i<m;++i){
			scanf("%d",&tmp);
			res=res/__gcd(res,tmp)*tmp;
		}
		printf("%d\n",res);
	}
	return 0;
}