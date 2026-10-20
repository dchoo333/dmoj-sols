#include <bits/stdc++.h>
using namespace std;
static char buf[1<<25];int bp=0,bl=0;
inline int gc(){if(bp==bl){bl=fread(buf,1,sizeof buf,stdin);bp=0;if(bl<=0)return -1;}return buf[bp++];}
inline long long rd(){int c=gc();while(c!='-'&&(c<'0'||c>'9'))c=gc();long long x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    long long n=rd(),m=rd(),s=n*m;
    vector<int>a(s),b(s);
    for(auto&x:a)x=rd();
    int q=rd();
    long long p=1,md=s-1;
    while(q--){
        int t=rd();
        if(t==1){if(md)p=p*(n%md)%md;swap(n,m);}
        else{long long k=rd();n=k;m=s/k;}
    }
    if(md==0)b=a;
    else{for(long long x=0;x<md;x++)b[x*p%md]=a[x];b[md]=a[md];}
    string o;o.reserve(s*11+32);
    o+=to_string(n)+" "+to_string(m)+"\n";
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){o+=to_string(b[i*m+j]);o+=j+1<m?' ':'\n';}
    }
    fwrite(o.data(),1,o.size(),stdout);
}