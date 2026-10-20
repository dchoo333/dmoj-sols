#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<int>p(n+1,0);
    vector<ll>d(n+1,0),s(n+1),z(n+1,1);
    for(int i=2;i<=n;i++){scanf("%d",&p[i]);d[i]=d[p[i]]+1;}
    for(int i=1;i<=n;i++)s[i]=d[i];
    for(int i=n;i>1;i--){s[p[i]]+=s[i];z[p[i]]+=z[i];}
    string o;
    for(int i=1;i<=n;i++){o+=to_string(s[i]-z[i]*d[i]+z[i]);o+=i<n?' ':'\n';}
    fputs(o.c_str(),stdout);
}