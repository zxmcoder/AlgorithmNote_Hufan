#include<bits/stdc++.h>
using namespace std;
void add(string a,string b){
    string s;
    int i=a.size()-1;
    int j=b.size()-1;
    int front=0;
    int temp;
    while(i>=0&&j>=0){
        temp=((a[i--]-'0')+(b[j--]-'0'))+front;
        front=temp/10;
        temp%=10;
        s+=(temp+'0');
    }
    while(i>=0){
        temp=(a[i--]-'0')+front;
        front=temp/10;
        temp%=10;
        s+=(temp+'0');
    }
    while(j>=0){
        temp=(b[j--]-'0')+front;
        front=temp/10;
        temp%=10;
        s+=(temp+'0');
    }
    if(front!=0)s+=(front+'0');
    reverse(s.begin(),s.end());
    cout<<s;
}
int main(){
    string a,b;
    cin>>a>>b;
    add(a,b);
    return 0;
}