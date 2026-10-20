#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int sb,n;scanf("%d %d",&sb,&n);
    static char b[200005];scanf("%s",b);
    vector<int>sc(n+1),pv(n+1),nx(n+1);
    for(int i=1;i<=n;i++){sc[i]=b[i-1]-'0';nx[i]=i%n+1;pv[i]=(i+n-2)%n+1;}
    unordered_map<ll,vector<int>>d;
    d.reserve(2*n);
    auto key=[&](ll x,ll y){if(x>y)swap(x,y);return x*(n+1)+y;};
    for(int i=0;i<n-3;i++){int x,y,c;scanf("%d %d %d",&x,&y,&c);d[key(x,y)].push_back(c);}
    vector<char>al(n+1,1);
    vector<int>st;
    for(int i=1;i<=n;i++)st.push_back(i);
    int left=n;bool bad=0;
    while(left>3&&!st.empty()){
        int v=st.back();st.pop_back();
        if(!al[v])continue;
        int p=pv[v],q=nx[v];
        auto it=d.find(key(p,q));
        if(it==d.end()||it->second.empty())continue;
        int c=it->second.back();it->second.pop_back();
        int a=sc[p],e=sc[v];
        if(a==e||a==c||e==c)bad=1;
        al[v]=0;left--;nx[p]=q;pv[q]=p;sc[p]=c;
        st.push_back(p);st.push_back(q);
    }
    if(left>3){puts("neispravna triangulacija");return 0;}
    int v=1;while(!al[v])v++;
    int x=sc[v],y=sc[nx[v]],z=sc[nx[nx[v]]];
    if(x==y||x==z||y==z)bad=1;
    puts(bad?"neispravno bojenje":"tocno");
}