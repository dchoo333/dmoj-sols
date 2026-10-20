#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<string,int>>v(n+m);
    for(int i=0;i<n+m;i++){cin>>v[i].first;v[i].second=i>=n;}
    sort(v.begin(),v.end());
    int t=n+m;
    vector<int>last(28,-1);
    for(int i=0;i<t;i++)last[v[i].first[0]-'a'+1]=i;
    for(int c=1;c<28;c++)last[c]=max(last[c],last[c-1]);
    vector<char>w(t);
    int nw[2]={INT_MAX,INT_MAX};
    for(int i=t-1;i>=0;i--){
        int c=v[i].first[0]-'a',b=last[min(c+2,27)],o=v[i].second^1;
        w[i]=!(nw[o]<=b);
        if(w[i])nw[v[i].second]=i;
    }
    int s=0;while(v[s].second)s++;
    puts(w[s]?"Leona":"Zoe");
}