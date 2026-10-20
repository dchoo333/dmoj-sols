#include<bits/stdc++.h>
using namespace std;
const long long M=1000000007;
int n,p[100005],o[100005];
vector<int>a[100005];
long long w[100005],b[100005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int t=0;
    o[t++]=1;
    p[1]=0;
    for(int i=0;i<t;i++){
        int v=o[i];
        for(int c:a[v])if(c!=p[v]){p[c]=v;o[t++]=c;}
    }
    for(int i=1;i<=n;i++){w[i]=1;b[i]=1;}
    for(int i=n-1;i>=0;i--){
        int v=o[i];
        if(v!=1){
            w[p[v]]=w[p[v]]*((w[v]+b[v])%M)%M;
            b[p[v]]=b[p[v]]*w[v]%M;
        }
    }
    printf("%lld\n",(w[1]+b[1])%M);
    return 0;
}
