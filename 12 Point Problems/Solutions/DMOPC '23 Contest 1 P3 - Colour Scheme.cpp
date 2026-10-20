#include<bits/stdc++.h>
using namespace std;
int q(int l,int r){
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int x;scanf("%d",&x);
    if(x<0)exit(0);
    return x;
}
int main(){
    int n;scanf("%d",&n);
    vector<int>b(n+1);
    vector<pair<int,int>>L;
    int p=0,k=0;
    for(int i=1;i<=n;i++){
        int t=i==1?1:q(1,i);
        if(t>p){
            b[i]=++k;
            L.push_back({i,k});
        }else{
            int c=L.size(),lo=1,hi=c;
            while(lo<hi){
                int m=(lo+hi+1)/2;
                if(q(L[m-1].first,i)==c-m+1)lo=m;
                else hi=m-1;
            }
            b[i]=L[lo-1].second;
            L.erase(L.begin()+lo-1);
            L.push_back({i,b[i]});
        }
        p=t;
    }
    printf("!");
    for(int i=1;i<=n;i++)printf(" %d",b[i]);
    printf("\n");
    fflush(stdout);
}