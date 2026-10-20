#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    double x,y;
    int n,m;
    scanf("%lf %lf %d %d",&x,&y,&n,&m);
    ll X=llround(x*10),Y=llround(y*10);
    int T=0;
    vector<int>c(n);
    for(int i=0;i<n;i++){scanf("%d",&c[i]);T+=c[i];}
    bitset<50001>b;
    b[0]=1;
    for(int i=0;i<n;i++)b|=b<<c[i];
    vector<int>nx(T+2,INT_MAX);
    int u=INT_MAX;
    for(int v=T;v>=0;v--){if(b[v])u=v;nx[v]=u;}
    vector<ll>A(m),B(m);
    vector<int>C(m),r(m);
    for(int i=0;i<m;i++){
        double a,q;
        int k;
        scanf("%lf %lf %d",&a,&q,&k);
        A[i]=llround(a*10);B[i]=llround(q*10);C[i]=k;
        ll dx=A[i]-X,dy=B[i]-Y,D=dx*dx+dy*dy;
        int s=0;
        while(100LL*s*s<D)s++;
        r[i]=s;
    }
    for(int i=0;i<m;i++)for(int j=0;j<m;j++){
        if(i==j||C[i]==C[j]||r[i]>T)continue;
        int s=nx[r[i]];
        if(s==INT_MAX||T-s<r[j])continue;
        printf("Harry can connect to outlets at (%.1f, %.1f) and (%.1f, %.1f).\n",A[i]/10.0,B[i]/10.0,A[j]/10.0,B[j]/10.0);
        return 0;
    }
    puts("Harry is helpless.");
    return 0;
}