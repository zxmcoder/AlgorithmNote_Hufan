/*
map<key,value>按照key值的从小到大进行排序
可以思考：如何按照自己想要的办法对map进行排序
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<2*n;++i){
        cin>>s;
        m[s]++;
    }
    int mx=0;
    for(auto it=m.begin();it!=m.end();++it){
        if(mx<it->second)
            mx=it->second;
    } 
    int cnt=0;
    map<string,int>::iterator ans;
    for(auto it=m.begin();it!=m.end();++it)
        if(mx==it->second){
            cnt++;
            ans=it;
        }
    if(cnt==1)cout<<ans->first<<" "<<ans->second;
    else{
        for(auto it=m.begin();it!=m.end();++it)
            if(ans->second==it->second){
                cout<<it->first<<" "<<it->second<<" "<<cnt;
                break;
            }
    }
    return 0;
}