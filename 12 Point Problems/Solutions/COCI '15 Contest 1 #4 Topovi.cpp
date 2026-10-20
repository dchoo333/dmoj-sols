#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>rx,cx;
map<int,ll>cr,cc;
map<pair<int,int>,int>p;
ll n,s;
void ur(int r,int x){
    int a=rx[r],b=a^x;
    s-=cc[a];cr[a]--;
    cr[b]++;s+=cc[b];
    rx[r]=b;
}
void uc(int c,int x){
    int a=cx[c],b=a^x;
    s-=cr[a];cc[a]--;
    cc[b]++;s+=cr[b];
    cx[c]=b;
}
void tg(int r,int c,int x){ur(r,x);uc(c,x);}
int main(){
    int k,q;
    scanf("%lld %d %d",&n,&k,&q);
    cr[0]=n;cc[0]=n;s=n*n;
    for(int i=0;i<k;i++){
        int r,c,x;scanf("%d %d %d",&r,&c,&x);
        p[{r,c}]=x;
        tg(r,c,x);
    }
    string o;
    while(q--){
        int a,b,c,d;scanf("%d %d %d %d",&a,&b,&c,&d);
        int x=p[{a,b}];
        p.erase({a,b});
        tg(a,b,x);
        p[{c,d}]=x;
        tg(c,d,x);
        o+=to_string(n*n-s);
        o+='\n';
    }
    fputs(o.c_str(),stdout);
}