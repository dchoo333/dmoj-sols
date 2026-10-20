#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<pair<ll,ll>>v(n);
    for(auto&[l,r]:v){ll x,d;scanf("%lld %lld",&x,&d);l=x-d;r=-(x+d);}
    sort(v.begin(),v.end());
    vector<array<ll,3>>s;
    ll a=1+n;
    auto pp=[&](){
        auto t=s.back();s.pop_back();
        if(t[2]==t[1])a++;
        if(!s.empty()){
            auto&p=s.back();
            p[2]=p[2]==t[0]?t[1]:LLONG_MIN;
        }
    };
    for(auto[l,r]:v){
        r=-r;
        while(!s.empty()&&s.back()[1]<=l)pp();
        s.push_back({l,r,l});
    }
    while(!s.empty())pp();
    printf("%lld\n",a);
}