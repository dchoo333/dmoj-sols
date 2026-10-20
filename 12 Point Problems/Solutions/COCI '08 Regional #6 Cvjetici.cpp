#include<bits/stdc++.h>
using namespace std;
const int M=100005;int f[M];
void ad(int i,int v){for(;i<M;i+=i&-i)f[i]+=v;}
int q(int i){int r=0;for(;i;i-=i&-i)r+=f[i];return r;}
int main(){
    int n;scanf("%d",&n);
    string o;
    while(n--){
        int l,r;scanf("%d %d",&l,&r);
        int a=q(l),b=q(r);
        ad(l,-a);ad(l+1,a);ad(r,-b);ad(r+1,b);
        if(l+1<r){ad(l+1,1);ad(r,-1);}
        o+=to_string(a+b);o+='\n';
    }
    fputs(o.c_str(),stdout);
}