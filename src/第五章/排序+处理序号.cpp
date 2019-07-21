//处理序号问题的时候：相等等于前面的排名，不相等等于所处位置。
//https://pintia.cn/problem-sets/15/problems/888
#include<bits/stdc++.h>
using namespace std;

struct node{
    string id;
    int room,score,allrank,rank;
    node(string _id,int _room,int _score):id(_id),room(_room),score(_score){}
};

vector<node> ans;

bool cmp(const node &one,const node &two){
    if(one.score!=two.score)return one.score>two.score;
    return one.id<two.id;
}

bool vis[105];
int pre[105];
int befcnt[105];

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;
    string tmp1;
    int tmp2;
    for(int i=1;i<=t;++i){
        cin>>n;
        for(int j=0;j<n;++j){
            cin>>tmp1>>tmp2;
            ans.push_back(node(tmp1,i,tmp2));
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end(),cmp);
    ans[0].allrank=1;
    for(int i=1;i<ans.size();++i){
        if(ans[i].score!=ans[i-1].score)
            ans[i].allrank=i+1;
        else
            ans[i].allrank=ans[i-1].allrank;
    }
    for(int i=0;i<ans.size();++i){
        if(vis[ans[i].room]==false){
            vis[ans[i].room]=true;
            ans[i].rank=1;
        }
        else{
            if(ans[i].score!=ans[pre[ans[i].room]].score)
                ans[i].rank=befcnt[ans[i].room]+1;
            else
                ans[i].rank=ans[pre[ans[i].room]].rank;
        }
        pre[ans[i].room]=i;
        befcnt[ans[i].room]++;
    }
    for(int i=0;i<ans.size();++i)
        cout<<ans[i].id<<" "<<ans[i].allrank<<" "<<ans[i].room<<" "<<ans[i].rank<<endl;
    return 0;
}