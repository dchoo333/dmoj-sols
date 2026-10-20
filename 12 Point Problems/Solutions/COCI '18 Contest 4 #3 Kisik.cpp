#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd(),k=rd();
    vector<pair<int,int>>v(n);
    for(auto&[h,w]:v){w=rd();h=rd();}
    sort(v.begin(),v.end());
    priority_queue<int>q;
    ll s=0,r=LLONG_MAX;
    for(auto[h,w]:v){
        q.push(w);s+=w;
        if((int)q.size()>k){s-=q.top();q.pop();}
        if((int)q.size()==k)r=min(r,s*h);
    }
    printf("%lld\n",r);
}