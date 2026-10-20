#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long u;
int main(){
    int n;
    if(scanf("%d",&n)!=1)return 0;
    mt19937_64 R(12345);
    while(n--){
        long long r;
        printf("0\n");fflush(stdout);
        if(scanf("%lld",&r)!=1||r<0)return 0;
        if(!r)continue;
        int L=r,c=1;
        u k=1ULL<<(L-1);
        while(1){
            u g=k;
            int e=L-c;
            if(e>0)g|=R()&((1ULL<<e)-1);
            printf("%llu\n",g);fflush(stdout);
            if(scanf("%lld",&r)!=1||r<0)return 0;
            if(!r)break;
            int P=L-(int)(r/2),p=L-1-P;
            k=g&~((1ULL<<(p+1))-1);
            if(!((g>>p)&1ULL))k|=1ULL<<p;
            c=P+1;
        }
    }
    return 0;
}
