#include <bits/stdc++.h>
using namespace std;
const int M=100000000;
vector<bool>c(M/2+1);
bool ip(long long x){
    if(x==2)return 1;
    if(x<2||x%2==0)return 0;
    return !c[x/2];
}
int main(){
    for(long long i=3;i*i<=M;i+=2)if(!c[i/2])for(long long j=i*i;j<=M;j+=2*i)c[j/2]=1;
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        vector<long long>a(n),p(n+1,0);
        for(int i=0;i<n;i++){scanf("%lld",&a[i]);p[i+1]=p[i]+a[i];}
        int bl=-1,bs=-1;
        for(int l=2;l<=n&&bl<0;l++)
            for(int s=0;s+l<=n;s++)
                if(ip(p[s+l]-p[s])){bl=l;bs=s;break;}
        if(bl<0){puts("This sequence is anti-primed.");continue;}
        printf("Shortest primed subsequence is length %d:",bl);
        for(int i=bs;i<bs+bl;i++)printf(" %lld",a[i]);
        printf("\n");
    }
}