#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<25];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline ll rd(){int c=gc();while(c<'0')c=gc();ll x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd();
    vector<ll>x(n),y(n);
    for(int i=0;i<n;i++){x[i]=rd();y[i]=rd();}
    int s=rd()-1;
    vector<ll>d(n,LLONG_MAX);
    vector<char>v(n,0);
    d[s]=0;
    for(int it=0;it<n;it++){
        int u=-1;
        for(int i=0;i<n;i++)if(!v[i]&&(u<0||d[i]<d[u]))u=i;
        v[u]=1;
        for(int i=0;i<n;i++)if(!v[i]){
            ll a=x[i]-x[u],b=y[i]-y[u],w=d[u]+a*a+b*b;
            if(w<d[i])d[i]=w;
        }
    }
    sort(d.begin(),d.end());
    int q=rd();
    string o;
    o.reserve(q*6);
    char t[24];
    while(q--){
        ll z=rd();
        int r=upper_bound(d.begin(),d.end(),z)-d.begin();
        int l=0;
        if(!r)t[l++]='0';
        while(r){t[l++]='0'+r%10;r/=10;}
        while(l)o+=t[--l];
        o+='\n';
    }
    fwrite(o.data(),1,o.size(),stdout);
}