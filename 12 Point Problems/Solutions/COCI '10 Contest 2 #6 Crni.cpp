#include <bits/stdc++.h>
using namespace std;
const int P=10007;
int n;
vector<string>g;
vector<vector<long long>>cor(bool dn,bool rt){
    vector<vector<long long>>r(n,vector<long long>(n,0));
    vector<long long>h(n,0),c(n);
    for(int s=0;s<n;s++){
        int i=dn?n-1-s:s;
        for(int j=0;j<n;j++)h[j]=g[i][j]=='C'?h[j]+1:0;
        vector<int>st;
        for(int t=0;t<n;t++){
            int j=rt?n-1-t:t;
            while(!st.empty()&&h[st.back()]>=h[j])st.pop_back();
            int p=st.empty()?-1:st.back();
            long long w=st.empty()?t+1:abs(j-p);
            c[j]=(p<0?0:c[p])+h[j]*w;
            st.push_back(j);
            r[i][j]=(c[j]-(g[i][j]=='C'))%P;
        }
    }
    return r;
}
int main(){
    cin>>n;g.resize(n);for(auto&s:g)cin>>s;
    auto br=cor(0,0),bl=cor(0,1),tl=cor(1,1),tr=cor(1,0);
    vector<long long>rb(n,0),rt(n,0),cr(n,0),cl(n,0);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        rb[i]+=br[i][j];rt[i]+=tl[i][j];cr[j]+=br[i][j];cl[j]+=tl[i][j];
    }
    long long a=0,s=0;
    for(int i=0;i+1<n;i++){s=(s+rb[i])%P;a=(a+s*(rt[i+1]%P))%P;}
    s=0;
    for(int j=0;j+1<n;j++){s=(s+cr[j])%P;a=(a+s*(cl[j+1]%P))%P;}
    vector<vector<long long>>p(n+1,vector<long long>(n+2,0)),q(n+1,vector<long long>(n+2,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)p[i+1][j+1]=(p[i][j+1]+p[i+1][j]-p[i][j]+br[i][j]+P)%P;
        for(int j=n-1;j>=0;j--)q[i+1][j]=(q[i][j]+q[i+1][j+1]-q[i][j+1]+bl[i][j]+P)%P;
    }
    long long d=0;
    for(int i=1;i<n;i++)for(int j=0;j<n;j++){
        if(j>0)d=(d+tl[i][j]*p[i][j])%P;
        if(j+1<n)d=(d+tr[i][j]*q[i][j+1])%P;
    }
    printf("%lld\n",((a-d)%P+P)%P);
}