#include<bits/stdc++.h>
typedef long long ll;
ll f[101][101];
int main(){
    for(int m=0;m<=100;m++)f[0][m]=1;
    for(int r=1;r<=100;r++)for(int m=1;m<=100;m++){
        f[r][m]=f[r][m-1];
        if(r>=m)f[r][m]+=f[r-m][m];
    }
    int n;
    scanf("%d",&n);
    while(n--){
        ll k,a;
        scanf("%lld %lld",&k,&a);
        if(a>f[k][k]){puts("Too big");continue;}
        printf("(");
        ll r=k,c=k;
        bool first=1;
        while(r>0){
            for(ll v=1;v<=c&&v<=r;v++){
                ll w=f[r-v][v<(r-v)?v:(r-v)];
                if(a>w)a-=w;
                else{
                    if(!first)printf(",");
                    printf("%lld",v);
                    first=0;
                    r-=v;c=v;
                    break;
                }
            }
        }
        printf(")\n");
    }
    return 0;
}