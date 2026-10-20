#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x;
    scanf("%lld %lld",&n,&x);
    if(n<3||x>(n-2)*(n-1)/2){puts("-1");return 0;}
    vector<char>in(n+1,0);
    for(ll w=n-2;w>=1&&x;w--)if(w<=x){in[n-1-w]=1;x-=w;}
    string o;
    for(ll i=1;i<=n-2;i++)if(!in[i]){o+=to_string(i);o+=' ';}
    o+=to_string(n);o+=' ';
    for(ll i=1;i<=n-2;i++)if(in[i]){o+=to_string(i);o+=' ';}
    o+=to_string(n-1);
    o+='\n';
    fputs(o.c_str(),stdout);
}