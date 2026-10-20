#include<bits/stdc++.h>
using namespace std;
typedef long double D;
int main(){
    int n;
    scanf("%d",&n);
    long long l,r,x,y;
    scanf("%lld %lld %lld %lld",&l,&r,&x,&y);
    vector<pair<D,D>>v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        long long a,b,c,d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        D p=a-(D)b*(x-a)/(D)(y-b);
        D q=c-(D)d*(x-c)/(D)(y-d);
        if(p>q)swap(p,q);
        if(q<(D)l||p>(D)r)continue;
        if(p<(D)l)p=l;
        if(q>(D)r)q=r;
        v.push_back({p,q});
    }
    sort(v.begin(),v.end());
    D b=0;
    size_t i=0;
    while(i<v.size()){
        D s=v[i].first,e=v[i].second;
        i++;
        while(i<v.size()&&v[i].first<=e){if(v[i].second>e)e=v[i].second;i++;}
        b+=e-s;
    }
    printf("%.6Lf\n",(D)(r-l)-b);
    return 0;
}