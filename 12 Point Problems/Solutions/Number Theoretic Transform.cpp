#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long u;
typedef __int128 L;
u g(u a,u b){while(b){u t=a%b;a=b;b=t;}return a;}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        u n,e,a,b;
        scanf("%llu %llu %llu %llu",&n,&e,&a,&b);
        u s=(u)(((L)a+b)%n),d=(u)(((L)a+n-b)%n);
        u p=g(s,n),q=g(d,n);
        if(p==0||p==n)p=0;
        if(q==0||q==n)q=0;
        if(p>1&&p<n)q=n/p;
        else if(q>1&&q<n)p=n/q;
        else{
            u r=(u)sqrtl((long double)n);
            while(r>1&&(L)r*r>(L)n)r--;
            while((L)(r+1)*(r+1)<=(L)n)r++;
            p=r;q=n/r;
        }
        if(p>q){u z=p;p=q;q=z;}
        printf("%llu %llu\n",p,q);
    }
    return 0;
}