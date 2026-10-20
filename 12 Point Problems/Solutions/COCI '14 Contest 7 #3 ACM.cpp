#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<array<int,3>>a(n);
    for(int j=0;j<3;j++)for(int i=0;i<n;i++)scanf("%d",&a[i][j]);
    int p[3]={0,1,2};
    long long r=LLONG_MAX;
    const long long I=LLONG_MAX/4;
    do{
        long long d[3]={a[0][p[0]],I,I};
        for(int i=1;i<n;i++){
            long long e[3];
            e[0]=d[0]+a[i][p[0]];
            e[1]=min(d[0],d[1])+a[i][p[1]];
            e[2]=min(d[1],d[2])+a[i][p[2]];
            memcpy(d,e,sizeof d);
        }
        r=min(r,d[2]);
    }while(next_permutation(p,p+3));
    printf("%lld\n",r);
}