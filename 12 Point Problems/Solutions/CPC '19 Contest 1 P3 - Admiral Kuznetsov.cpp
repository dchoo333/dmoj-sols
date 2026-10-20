#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;static char a[1000005],b[1000005];scanf("%d %s %s",&n,a+1,b+1);
    vector<int>c(n+1,0);
    for(int i=1;i<=n;i++)c[i]=c[i-1]+1-(a[i]=='1')+(b[i]=='1');
    const int I=1e9,f[6]={0,0,0,1,1,3};
    vector<int>d(n+1,I);d[0]=0;
    for(int i=1;i<=n;i++){
        if(!(a[i]=='1'&&b[i]=='0'))d[i]=d[i-1]+(a[i]=='0'&&b[i]=='1');
        for(int w=3;w<=5;w++)if(i>=w&&d[i-w]<I)d[i]=min(d[i],d[i-w]+c[i]-c[i-w]+f[w]);
    }
    printf("%d\n",d[n]<I?d[n]:-1);
}