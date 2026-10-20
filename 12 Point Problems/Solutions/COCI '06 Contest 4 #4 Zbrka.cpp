#include <bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int main(){
    int n,c;scanf("%d %d",&n,&c);
    vector<long long>f(c+1,0),g(c+1);
    f[0]=1;
    for(int i=2;i<=n;i++){
        long long s=0;
        for(int x=0;x<=c;x++){
            s=(s+f[x])%P;
            if(x-i>=0)s=(s-f[x-i]+P)%P;
            g[x]=s;
        }
        swap(f,g);
    }
    printf("%lld\n",f[c]);
}
