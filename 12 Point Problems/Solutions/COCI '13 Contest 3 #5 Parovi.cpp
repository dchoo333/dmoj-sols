#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
int L;
vector<ll>pw;
vector<array<ll,10>>cn(const string&s){
    vector<ll>pr(L+1,0),sf(L+1,0);
    for(int i=0;i<L;i++)pr[i+1]=(pr[i]*10+s[i]-'0')%P;
    for(int i=L-1;i>=0;i--)sf[i]=((s[i]-'0')*pw[L-1-i]+sf[i+1])%P;
    vector<array<ll,10>>r(L);
    for(int i=0;i<L;i++){
        ll h=pr[i],w=pw[L-1-i],l=sf[i+1];
        int c=s[i]-'0';
        for(int d=0;d<10;d++){
            ll v=h*w%P;
            if(d<c)v+=w;
            else if(d==c)v+=l+1;
            r[i][d]=v%P;
        }
    }
    return r;
}
int main(){
    string a,b;
    cin>>a>>b;
    L=b.size();
    int i=a.size()-1;
    while(a[i]=='0'){a[i]='9';i--;}
    a[i]--;
    a=string(L-a.size(),'0')+a;
    pw.assign(L+1,1);
    for(int j=1;j<=L;j++)pw[j]=pw[j-1]*10%P;
    auto x=cn(b),y=cn(a);
    ll r=0;
    for(int j=0;j<L;j++){
        ll c[10];
        for(int d=0;d<10;d++)c[d]=(x[j][d]-y[j][d]+P)%P;
        for(int d=0;d<10;d++)for(int e=0;e<10;e++)
            r=(r+c[d]*c[e]%P*abs(d-e))%P;
    }
    printf("%lld\n",r);
}