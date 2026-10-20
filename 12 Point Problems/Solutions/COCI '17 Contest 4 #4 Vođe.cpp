#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;scanf("%d %d %d",&n,&m,&k);
    vector<int>t(n);
    for(auto&x:t)scanf("%d",&x);
    vector<char>w((size_t)m*n);
    vector<int>c(n,0);
    for(int j=m-1;j>=0;j--){
        int a=j+1,b=j+k+1;
        if(a<m)for(int p=0;p<n;p++)c[p]+=w[(size_t)a*n+p];
        if(b<m)for(int p=0;p<n;p++)c[p]-=w[(size_t)b*n+p];
        int tot=min(j+k,m-1)-j;
        for(int p=0;p<n;p++){
            int q=(p+1)%n,o=c[q];
            char r;
            if(tot<=0)r=1-t[p];
            else if(t[p]==1)r=o>0;
            else r=!(o<tot);
            w[(size_t)j*n+p]=r;
        }
    }
    for(int p=0;p<n;p++)printf("%d%c",w[p],p+1<n?' ':'\n');
}