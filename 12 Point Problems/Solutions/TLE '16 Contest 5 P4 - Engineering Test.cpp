#include<bits/stdc++.h>
using namespace std;
typedef __int128 L;
int main(){
    long long k;int n;
    scanf("%lld %d",&k,&n);
    vector<L>c(n);
    for(auto&x:c){long long v;scanf("%lld",&v);x=(L)v+k;}
    sort(c.rbegin(),c.rend());
    vector<L>p,w;
    int h=0;
    for(int r=1;;r++){
        if((long long)r*(r+1)/2>n)break;
        vector<L>q(r);
        for(int j=0;j<r;j++){
            L s=k;
            if(j>0)s+=(p[j-1]+1)/2;
            if(j<r-1)s+=(p[j]+1)/2;
            q[j]=s;
        }
        for(auto x:q)w.push_back(x);
        vector<L>d=w;
        sort(d.rbegin(),d.rend());
        bool f=1;
        for(int i=0;i<(int)d.size();i++)if(c[i]<d[i]){f=0;break;}
        if(!f)break;
        h=r;
        p=q;
    }
    printf("%d\n",h);
}