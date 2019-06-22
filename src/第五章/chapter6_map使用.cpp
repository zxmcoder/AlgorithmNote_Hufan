#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    getline(cin,s);
    //cout<<s<<endl;
    map<string,int> cnt;
    string t;
    for(int i=0;i<s.size();++i){
        if(isalnum(s[i])){
            s[i]=tolower(s[i]);
            t+=s[i];
        }
        if(!isalnum(s[i])||i==s.size()-1){
            if(t.size()!=0)cnt[t]++;
            t="";
        }
    }
    int maxn=0;
    for(auto it=cnt.begin();it!=cnt.end();++it){
        if(it->second>maxn){
            t=it->first;
            maxn=it->second;
        }
    }
    cout<<t<<" "<<maxn;
    return 0;
}
/**************************************************************
    Problem: 6168
    User: coderzxm
    Language: C++
    Result: 正确
    Time:100 ms
    Memory:4984 kb
****************************************************************/