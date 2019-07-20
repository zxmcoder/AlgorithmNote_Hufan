//CCCCL2紧急救援
//https://pintia.cn/problem-sets/994805046380707840/problems/994805073643683840
//主要是要注意初始化问题和当松弛相等的情况
#include<bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int mp[505][505];
int weight[505];
int vis[505];
int dis[505],w[505],num[505],pre[505];

int main(){
    ios::sync_with_stdio(false);
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;++i)cin>>weight[i];
    fill(mp[0],mp[0]+505*505,inf);
    fill(dis,dis+505,inf);
    memset(w,0,sizeof(w));
    memset(pre,-1,sizeof(pre));
    num[s]=1;
    dis[s]=0;
    w[s]=weight[s];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(i==j)mp[i][j]=0;
        }
    int tmpa,tmpb,tmpw;
    for(int i=0;i<m;++i){
        cin>>tmpa>>tmpb>>tmpw;
        mp[tmpa][tmpb]=tmpw;
        mp[tmpb][tmpa]=tmpw;
    }
    for(int i=0;i<n;++i){
        int u=-1,mn=inf;
        for(int j=0;j<n;++j){
            if(vis[j]==false&&mn>dis[j]){
                u=j;
                mn=dis[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int v=0;v<n;++v){
            if(vis[v]==false&&mp[u][v]!=inf){
                if(dis[u]+mp[u][v]<dis[v]){
                    pre[v]=u;
                    dis[v]=dis[u]+mp[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }
                else if(dis[u]+mp[u][v]==dis[v]){
                    if(w[v]<w[u]+weight[v]){
                        pre[v]=u;
                        w[v]=w[u]+weight[v];
                    }
                    num[v]+=num[u];
                }
            }
        }
    }
    cout<<num[d]<<" "<<w[d]<<endl;
    vector<int> ans;
    int st=d;
    //cout<<pre[0]<<endl;
    while(st!=-1){
        ans.push_back(st);
        st=pre[st];
        //cout<<"yes"<<endl;
    }
    //cout<<"yes";
    cout<<s;
    for(int i=ans.size()-2;i>=0;--i)
        cout<<" "<<ans[i];
    return 0;
}