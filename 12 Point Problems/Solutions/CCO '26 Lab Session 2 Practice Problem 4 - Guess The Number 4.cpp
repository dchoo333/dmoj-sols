#include<bits/stdc++.h>
using namespace std;
long long c[60][16];
long long f(int q,int l){if(q<=0||l<0)return 0;return c[q][l];}
long long pk(long long lo,long long hi,int q,int l){
    long long a=f(q-2,l);
    if(a>hi-lo)a=hi-lo;
    return lo+a;
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(int q=1;q<=55;q++)for(int l=0;l<=14;l++)c[q][l]=f(q-2,l)+1+f(q-1,l-1);
    long long lo=1,hi=n,g,h;
    int q=50,l=14;
    char s[30],t[30];
    g=pk(lo,hi,q-1,l);
    printf("%lld\n",g);fflush(stdout);q--;
    while(1){
        h=g<hi?pk(g+1,hi,q-1,l-1):g;
        printf("%lld\n",h);fflush(stdout);q--;
        if(scanf("%s %s",s,t)!=2)return 0;
        if(s[0]=='j')return 0;
        if(t[0]=='l'){lo=g+1;l--;g=h;}
        else if(t[0]=='h'){
            hi=g-1;
            if(lo>hi)return 0;
            g=pk(lo,hi,q-1,l);
            printf("%lld\n",g);fflush(stdout);q--;
            if(scanf("%s %s",s,t)!=2)return 0;
            if(s[0]!='t'||t[0]!='h')return 0;
        }
        else return 0;
    }
}