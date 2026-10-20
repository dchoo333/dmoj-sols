#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9;
int main(){
    int n;scanf("%d",&n);
    if(n<2){puts("0");return 0;}
    vector<int>m;
    for(int a=1;a<=n;a++)for(int b=a+1;b<=n;b++)if(__gcd(a,b)==1){
        int k=0;
        for(int x=a+1;x<=b;x++)k|=1<<(x-2);
        m.push_back(k);
    }
    vector<ll>pw(m.size()+1,1);
    for(size_t i=1;i<pw.size();i++)pw[i]=pw[i-1]*2%P;
    int c=n-1;
    ll r=0;
    for(int u=0;u<(1<<c);u++){
        int p=0;
        for(int k:m)if(!(k&u))p++;
        if(__builtin_popcount(u)&1)r=(r-pw[p]+P)%P;
        else r=(r+pw[p])%P;
    }
    printf("%lld\n",r);
}