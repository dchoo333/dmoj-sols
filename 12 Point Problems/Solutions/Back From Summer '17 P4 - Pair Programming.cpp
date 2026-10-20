#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>pa(n+1,0),g(n+1,0),st(n+1,0);
    vector<int>hd(n+1,-1),nx(n+1,-1);
    vector<int>q;
    for(int i=1;i<=n;i++){
        char t[4],s[4];
        scanf("%s",t);
        if(t[0]=='C'){pa[i]=0;scanf("%s",s);}
        else{scanf("%d %s",&pa[i],s);}
        g[i]=(s[0]=='W')?1:0;
        st[i]=(s[0]=='?')?1:0;
        nx[i]=hd[pa[i]];hd[pa[i]]=i;
    }
    vector<int>vl(n+1,0),gp(n+1,0),ord;
    ord.reserve(n);
    for(int e=hd[0];e>=0;e=nx[e])ord.push_back(e);
    for(size_t i=0;i<ord.size();i++){
        int u=ord[i],p=pa[u];
        vl[u]=vl[p]^g[u];
        gp[u]=st[u]?u:gp[p];
        for(int e=hd[u];e>=0;e=nx[e])ord.push_back(e);
    }
    vector<ll>A(n+1,0),B(n+1,0);
    for(int i=1;i<=n;i++){
        if(vl[i])A[gp[i]]++;else B[gp[i]]++;
    }
    ll lo=0,hi=0;
    for(int i=0;i<=n;i++){
        if(i==0){lo+=A[0];hi+=A[0];}
        else if(st[i]){lo+=min(A[i],B[i]);hi+=max(A[i],B[i]);}
    }
    printf("%lld %lld\n",lo,hi);
    return 0;
}