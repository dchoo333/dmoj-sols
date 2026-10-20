#include<bits/stdc++.h>
int n,q;
long long a[200005],t[200005];
void u(int i,long long v){for(;i<=n;i+=i&-i)t[i]+=v;}
long long s(int i){long long r=0;for(;i;i-=i&-i)r+=t[i];return r;}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){scanf("%lld",&a[i]);u(i,a[i]);}
    while(q--){
        char c[4];
        int x,y;
        scanf("%s %d %d",c,&x,&y);
        if(c[0]=='S')printf("%lld\n",s(y)-s(x-1));
        else{u(x,y-a[x]);a[x]=y;}
    }
    return 0;
}