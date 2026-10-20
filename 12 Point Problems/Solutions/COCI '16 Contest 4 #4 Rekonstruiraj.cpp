#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll S=100000;
ll pr(string s){
    ll i=0,a=0,f=0,c=0;
    while(i<(ll)s.size()&&s[i]!='.')a=a*10+s[i++]-'0';
    if(i<(ll)s.size())i++;
    while(i<(ll)s.size()){f=f*10+s[i++]-'0';c++;}
    while(c<5){f*=10;c++;}
    return a*S+f;
}
int main(){
    ll k,a,b;
    cin>>k>>a>>b;
    a*=S;b*=S;
    vector<ll>v(k);
    for(auto&x:v){string s;cin>>s;x=pr(s);}
    vector<char>u(k,0);
    vector<ll>r;
    auto in=[&](ll x){return binary_search(v.begin(),v.end(),x);};
    for(int i=0;i<k;i++){
        if(u[i])continue;
        ll x=v[i];
        vector<ll>d;
        for(ll j=1;j*j<=x;j++)if(x%j==0){d.push_back(j);if(j!=x/j)d.push_back(x/j);}
        sort(d.begin(),d.end());
        for(ll y:d){
            ll lo=(a+y-1)/y,hi=b/y;
            if(hi-lo+1>k)continue;
            bool ok=1;
            for(ll m=lo;m<=hi&&ok;m++)if(!in(m*y))ok=0;
            if(!ok)continue;
            for(ll m=lo;m<=hi;m++)u[lower_bound(v.begin(),v.end(),m*y)-v.begin()]=1;
            r.push_back(y);
            break;
        }
    }
    string o;
    for(ll y:r){
        o+=to_string(y/S);
        ll f=y%S;
        if(f){
            string t=to_string(f);
            t=string(5-t.size(),'0')+t;
            while(t.back()=='0')t.pop_back();
            o+='.'+t;
        }
        o+='\n';
    }
    cout<<o;
}