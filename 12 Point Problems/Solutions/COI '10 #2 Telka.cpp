#include<bits/stdc++.h>
using namespace std;
const int D=86400;
long long d[D+1],p[D+1];
void rd(int&a,int&b){int h,m,s,H,M,S;scanf("%d:%d:%d - %d:%d:%d",&h,&m,&s,&H,&M,&S);a=h*3600+m*60+s;b=H*3600+M*60+S;}
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int a,b;rd(a,b);
        if(a<=b){d[a]++;d[b+1]--;}
        else{d[a]++;d[D]--;d[0]++;d[b+1]--;}
    }
    long long c=0;
    for(int i=0;i<D;i++){c+=d[i];p[i+1]=p[i]+c;}
    int q;scanf("%d",&q);
    while(q--){
        int a,b;rd(a,b);
        long long s,l;
        if(a<=b){s=p[b+1]-p[a];l=b-a+1;}
        else{s=p[D]-p[a]+p[b+1];l=D-a+b+1;}
        printf("%.10f\n",(double)s/l);
    }
}