#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;ll s;scanf("%d %lld",&n,&s);
    vector<ll>a(n+2,0);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    vector<int>L(n+1),R(n+1);
    ll t=0;int j=1;
    for(int m=1;m<=n;m++){t+=a[m];while(t>s)t-=a[j++];L[m]=m-j+1;}
    t=0;j=n;
    for(int m=n;m>=1;m--){t+=a[m];while(t>s)t-=a[j--];R[m-1]=j-m+1;}
    R[n]=0;
    vector<vector<int>>b(n+2);
    for(int m=1;m<=n;m++){int c=min(L[m],R[m]);if(c>0)b[m-c+1].push_back(m);}
    int mx=0;
    string o;
    for(int i=1;i<=n;i++){
        for(int m:b[i])mx=max(mx,m);
        o+=to_string(mx>=i?2*(mx-i+1):0);o+='\n';
    }
    fputs(o.c_str(),stdout);
}