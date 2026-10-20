#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<ll>a(n);
    for(ll&x:a) cin>>x;

    sort(a.begin(),a.end());

    ll q=0;
    for(int i=0,j;i<n;i=j){
        j=i;
        while(j<n&&a[j]==a[i]) j++;
        ll c=j-i;
        q+=c*c;
    }

    ll s=q-n;

    int m=n*(n-1)/2;
    vector<ll>p;
    p.reserve(m);

    for(int j=0;j<n;j++)
        for(int i=0;i<j;i++)
            p.push_back(a[i]*a[j]);

    sort(p.begin(),p.end());

    ll t=0;
    for(int i=0,j;i<m;i=j){
        j=i;
        while(j<m&&p[j]==p[i]) j++;
        ll c=j-i;
        t+=c*(c-1);
    }

    cout<<4*(t-(ll)(n-2)*s)<<"\n";
}