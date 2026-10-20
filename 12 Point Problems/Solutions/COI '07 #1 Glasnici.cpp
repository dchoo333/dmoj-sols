#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rdr(){
    char s[64];scanf("%s",s);
    ll a=0,f=0;int c=0,i=0;
    while(s[i]&&s[i]!='.')a=a*10+s[i++]-'0';
    if(s[i])i++;
    while(s[i]&&c<3){f=f*10+s[i++]-'0';c++;}
    while(c<3){f*=10;c++;}
    return (a*1000+f)*2;
}
int n;ll k;vector<ll>x;
bool ok(ll t){
    ll p=x[0]+t;
    for(int i=1;i<n;i++){
        if(x[i]-t>p+k)return 0;
        p=min(x[i]+t,p+k);
    }
    return 1;
}
int main(){
    k=rdr();scanf("%d",&n);x.resize(n);
    for(auto&v:x)v=rdr();
    ll l=0,h=x[n-1]-x[0];
    while(l<h){ll m=(l+h)/2;if(ok(m))h=m;else l=m+1;}
    printf("%lld.%04lld\n",l/2000,l%2000*5);
}