#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll f(vector<ll>&a){
    vector<int>l(n),r(n),s;
    for(int i=0;i<n;i++){while(!s.empty()&&a[s.back()]<a[i])s.pop_back();l[i]=s.empty()?-1:s.back();s.push_back(i);}
    s.clear();
    for(int i=n-1;i>=0;i--){while(!s.empty()&&a[s.back()]<=a[i])s.pop_back();r[i]=s.empty()?n:s.back();s.push_back(i);}
    ll t=0;
    for(int i=0;i<n;i++)t+=a[i]*(i-l[i])*(r[i]-i);
    return t;
}
int main(){
    scanf("%d",&n);
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++){scanf("%lld",&a[i]);b[i]=-a[i];}
    printf("%lld\n",f(a)+f(b));
}