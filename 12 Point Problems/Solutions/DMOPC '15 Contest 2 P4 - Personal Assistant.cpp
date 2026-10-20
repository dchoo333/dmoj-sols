#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline ll rd(){int c=gc();while(c<'0')c=gc();ll x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd();
    vector<ll>r(n),l(n),h(n);
    for(int i=0;i<n;i++){r[i]=rd();l[i]=rd();h[i]=rd();}
    vector<ll>d(n+1,0);
    for(int i=n-1;i>=0;i--){
        int j=lower_bound(r.begin(),r.end(),r[i]+l[i])-r.begin();
        d[i]=max(d[i+1],h[i]+d[j]);
    }
    printf("%lld\n",d[0]);
}