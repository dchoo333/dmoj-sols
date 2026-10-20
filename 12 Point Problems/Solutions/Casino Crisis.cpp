#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;scanf("%d %d",&n,&q);
    vector<int>a(n+2);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    vector<pair<int,int>>o;
    for(int l=n-1;l>=1;l--){
        int x=a[l],r=l;
        while(r<n&&a[r+1]<x)r++;
        if(r==l)continue;
        o.push_back({l,r});
        if(r>l+1)o.push_back({l+1,r});
        for(int j=l;j<r;j++)a[j]=a[j+1];
        a[r]=x;
    }
    printf("%d\n",(int)o.size());
    for(auto&p:o)printf("%d %d\n",p.first,p.second);
}