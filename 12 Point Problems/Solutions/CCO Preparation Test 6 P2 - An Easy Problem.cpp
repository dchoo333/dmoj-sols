#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    int f[31]={0},r=0;
    for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        int d=1;
        for(int b=0;b<31;b++)if(a>>b&1)d=max(d,f[b]+1);
        for(int b=0;b<31;b++)if(a>>b&1)f[b]=max(f[b],d);
        r=max(r,d);
    }
    printf("%d\n",r);
}