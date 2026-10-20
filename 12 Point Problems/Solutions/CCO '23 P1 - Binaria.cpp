#include <bits/stdc++.h>
using namespace std;
const long long P=1000003;
long long pw(long long b,long long e){long long r=1;b%=P;while(e){if(e&1)r=r*b%P;b=b*b%P;e>>=1;}return r;}
int main(){
    int n,k;scanf("%d %d",&n,&k);
    int m=n-k+1;
    vector<int>s(m);
    for(auto&x:s)scanf("%d",&x);
    vector<int>v(k,-1);
    for(int i=0;i+1<m;i++){
        int d=s[i+1]-s[i],r=i%k;
        if(d&&v[r]<0)v[r]=d>0?0:1;
    }
    int f=0,c=s[0];
    for(int r=0;r<k;r++){if(v[r]<0)f++;else c-=v[r];}
    if(c<0||c>f){puts("0");return 0;}
    vector<long long>fa(f+1,1);
    for(int i=1;i<=f;i++)fa[i]=fa[i-1]*i%P;
    printf("%lld\n",fa[f]*pw(fa[c]*fa[f-c],P-2)%P);
}