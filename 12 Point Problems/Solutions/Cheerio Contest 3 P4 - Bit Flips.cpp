#include <bits/stdc++.h>
using namespace std;
int n,a[105],m[30][105][105],on[30][105];
int f(int l,int r,int b){
    if(l>r||b<0)return 0;
    int&v=m[b][l][r];
    if(v>=0)return v;
    v=INT_MAX;
    for(int k=l;k<=r+1;k++){
        int o=on[b][k]-on[b][l];
        int z=(r+1-k)-(on[b][r+1]-on[b][k]);
        v=min(v,o+z+f(l,k-1,b-1)+f(k,r,b-1));
    }
    return v;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int b=0;b<30;b++)for(int i=0;i<n;i++)on[b][i+1]=on[b][i]+(a[i]>>b&1);
    memset(m,-1,sizeof m);
    printf("%d\n",f(0,n-1,29));
}