#include<bits/stdc++.h>
using namespace std;
typedef __int128 L;
int n;
long long k,d;
vector<long long>a;
L f(L v){
    L s=0;
    for(int i=0;i<n;i++)if(a[i]>=v){
        s+=(L)((a[i]-v)/k)+1;
        if(s>(L)8e18)break;
    }
    return s;
}
int main(){
    while(scanf("%d %lld %lld",&n,&k,&d)==3){
        a.assign(n,0);
        long long mn=LLONG_MAX,mx=LLONG_MIN;
        for(int i=0;i<n;i++){scanf("%lld",&a[i]);mn=min(mn,a[i]);mx=max(mx,a[i]);}
        L lo=(L)mn-(L)(d/n+2)*k,hi=mx;
        while(lo<hi){
            L m=lo+(hi-lo+1)/2;
            if(f(m)>=(L)d)lo=m;else hi=m-1;
        }
        L c=f(lo+1),r=(L)d-c;
        for(int i=0;i<n;i++)if(a[i]>=lo&&((L)a[i]-lo)%k==0){
            if(--r==0){printf("%d\n",i+1);break;}
        }
    }
    return 0;
}