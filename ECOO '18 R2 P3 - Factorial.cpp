#include <bits/stdc++.h>
using namespace std;

bool f(long long n, vector<pair<int,int>>&v, int M){
    for(auto &x:v){
        long long a=0,p=x.first;
        while(n/p){
            a+=n/p;
            p*=x.first;
        }
        if(a<1LL*x.second*M) return 0;
    }
    return 1;
}

vector<pair<int,int>> g(int n){
    vector<pair<int,int>> r;
    int c=0;
    while(n%2==0){n/=2;c++;}
    if(c) r.push_back({2,c});
    for(int i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0){n/=i;c++;}
        if(c) r.push_back({i,c});
    }
    if(n>2) r.push_back({n,1});
    return r;
}

long long h(int M, vector<pair<int,int>>&v){
    long long l=0,r=1e12;
    while(l<r){
        long long m=l+(r-l)/2;
        if(f(m,v,M)) r=m;
        else l=m+1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int z=0;z<10;z++){
        int K,M;
        cin>>K>>M;
        auto v=g(K);
        cout<<h(M,v)<<"\n";
    }
}