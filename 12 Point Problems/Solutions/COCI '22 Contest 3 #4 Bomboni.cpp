#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int main(){
    int n,k;scanf("%d %d",&n,&k);
    vector<int>dv;
    for(int i=1;i<=k;i++)if(k%i==0)dv.push_back(i);
    int D=dv.size();
    vector<int>id(k+1,-1);
    for(int i=0;i<D;i++)id[dv[i]]=i;
    vector<vector<int>>tr(D,vector<int>(D));
    for(int i=0;i<D;i++)for(int j=0;j<D;j++)tr[i][j]=id[__gcd((long long)dv[i]*dv[j],(long long)k)];
    vector<vector<int>>a(n,vector<int>(n));
    for(auto&r:a)for(auto&x:r)scanf("%d",&x);
    vector<vector<int>>pr(n,vector<int>(D,0)),cu(n,vector<int>(D,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto&c=cu[j];
            fill(c.begin(),c.end(),0);
            if(a[i][j]<0)continue;
            int g=id[__gcd(a[i][j],k)];
            if(!i&&!j){c[g]=1;continue;}
            for(int t=0;t<D;t++){
                long long s=0;
                if(i)s+=pr[j][t];
                if(j)s+=cu[j-1][t];
                if(s){int u=tr[t][g];c[u]=(c[u]+s)%P;}
            }
        }
        swap(pr,cu);
    }
    printf("%d\n",pr[n-1][D-1]);
}