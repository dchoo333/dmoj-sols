#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c!='-'&&(c<'0'||c>'9'))c=gc();int s=1;if(c=='-'){s=-1;c=gc();}int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x*s;}
int main(){
    int n=rd(),k=rd(),l=n-k;
    vector<int>v(n);
    for(auto&x:v)x=rd();
    sort(v.begin(),v.end());
    vector<int>d(n-1),q(n);
    for(int i=0;i+1<n;i++)d[i]=v[i+1]-v[i];
    int h=0,t=0,w=l-1;
    long long r=LLONG_MAX;
    for(int i=0;i<n-1;i++){
        while(t>h&&d[q[t-1]]>=d[i])t--;
        q[t++]=i;
        if(q[h]<=i-w)h++;
        if(i>=w-1){
            int s=i-w+1;
            r=min(r,(long long)v[s+l-1]-v[s]+d[q[h]]);
        }
    }
    printf("%lld\n",r);
}