#include<bits/stdc++.h>
int p[1000001];
bool s[1000001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=2;i<=n;i++)if(p[i]==i)for(int j=i;j<=n;j+=i)p[j]-=p[j]/i;
    if(n>=1)s[1]=1;
    for(long long a=2;a*a<=n;a++)for(long long v=a*a;v<=n;v*=a)s[v]=1;
    long long r=0;
    for(int i=1;i<=n;i++)if(s[p[i]])r+=p[i];
    printf("%lld\n",r%1000000007);
    return 0;
}