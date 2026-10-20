#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll xe,ye,xh,yh,d;
    cin>>xe>>ye>>xh>>yh>>d;
    ll dx=xh-xe,dy=yh-ye,sx=dx<0?-1:1,sy=dy<0?-1:1,a=llabs(dx),b=llabs(dy),D=a+b;
    bool w=b>a;if(w)swap(a,b);
    ll e=d-D;
    if(e<0||e%2||(D==1&&e)||(a==1&&b==1&&e==2)){puts("impossible");return 0;}
    vector<pair<ll,ll>>t;
    if(e){
        ll T=a>=2?e/2-1:e/2-2;
        t.push_back({0,1});
        for(ll y=-T;y<=0;y++){t.push_back({1,y});t.push_back({-1,y});}
    }
    printf("%d\n",(int)t.size());
    for(auto&p:t){
        ll u=p.first,v=p.second;
        if(w)swap(u,v);
        printf("%lld %lld\n",xe+sx*u,ye+sy*v);
    }
}