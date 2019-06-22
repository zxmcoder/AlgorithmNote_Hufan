//筛选法求素数
//打表，一般情况下，打表10^5以内就可以解决int类型的质因子分解问题了
//质因子分解问题的关键：先把素数表打出来，然后开一个结构体，记录质因子和这个质因子出现的次数
//需要注意的是，一个数的质因子，只有0或者1个出现在sqrt(n)后面，只要判断小于等于sqrt(n)的情况，然后最后判断剩下的那个
#include<bits/stdc++.h>
using namespace std;
const int manx=100005;
bool f[manx];
vector<int> number;
void Find_Num(){
    for(int i=2;i<manx;++i){
        if(f[i]==false){
            for(int j=2;j*i<manx;++j)
                f[i*j]=true;
        }
    }
    for(int i=2;i<manx;++i)
        if(f[i]==false)
            number.push_back(i);
}
int main(){
    Find_Num();
    return 0;
}