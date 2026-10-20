#include <bits/stdc++.h>
using namespace std;
int n;string o;
int rv(int j,int k){int r=0;for(int b=0;b<k;b++)if(j>>b&1)r|=1<<(k-1-b);return r;}
void go(int k,int j){
    int v=k==n-1?(1<<k)+rv(j,k):(1<<(k+1))-1-rv(j,k);
    o+=to_string(v);o+=' ';
    if(k+1<n){go(k+1,2*j);go(k+1,2*j+1);}
}
int main(){
    scanf("%d",&n);
    go(0,0);
    o.pop_back();
    puts(o.c_str());
}