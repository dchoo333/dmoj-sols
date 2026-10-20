#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,H;scanf("%d %d",&n,&H);
    vector<ll>d(H+1,0),w(H+1);
    const ll I=LLONG_MIN/4;
    while(n--){
        ll g,h,q,t;scanf("%lld %lld %lld %lld",&g,&h,&q,&t);
        for(int c=0;c<=H;c++){
            w[c]=I;
            if(c>=h)w[c]=d[c-h]+g;
            if(c>=t&&w[c-t]>I)w[c]=max(w[c],w[c-t]+q);
        }
        for(int c=0;c<=H;c++)d[c]=max(d[c],w[c]);
    }
    printf("%lld\n",*max_element(d.begin(),d.end()));
}