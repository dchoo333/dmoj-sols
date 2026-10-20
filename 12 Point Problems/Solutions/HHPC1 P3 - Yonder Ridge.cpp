#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline ll rd(){int c=gc();while(c!='-'&&(c<'0'||c>'9'))c=gc();int s=1;if(c=='-'){s=-1;c=gc();}ll x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x*s;}
ll fl(ll a,ll b){return a>=0?a/b:-((-a+b-1)/b);}
int main(){
    int n=rd();ll m=rd();int q=rd();ll k=rd();
    vector<ll>a(n),b(n),v(n);
    for(int i=0;i<n;i++){a[i]=rd();b[i]=rd();v[i]=rd();}
    vector<vector<pair<ll,int>>>g(n);
    for(int i=0;i<q;i++){int p=rd()-1;ll s=rd();g[p].push_back({s,i});}
    vector<ll>r(q);
    for(int x=0;x<n;x++){
        if(g[x].empty())continue;
        vector<pair<ll,ll>>u,d;
        ll z=0;
        for(int j=0;j<n;j++){
            if(j==x)continue;
            ll A=a[j]-a[x],C=(b[j]-b[x])-A;
            if(C>0)u.push_back({fl(-A*m,C)+1-k,v[j]});
            else if(C<0)d.push_back({-fl(-A*m,-C)-1,v[j]});
            else if(A>0)z+=v[j];
        }
        sort(u.begin(),u.end());
        sort(d.begin(),d.end());
        vector<ll>pu(u.size()+1,0),pd(d.size()+1,0);
        for(size_t i=0;i<u.size();i++)pu[i+1]=pu[i]+u[i].second;
        for(size_t i=0;i<d.size();i++)pd[i+1]=pd[i]+d[i].second;
        for(auto[s,i]:g[x]){
            int c=upper_bound(u.begin(),u.end(),make_pair(s,LLONG_MAX))-u.begin();
            int e=lower_bound(d.begin(),d.end(),make_pair(s,LLONG_MIN))-d.begin();
            r[i]=z+pu[c]+pd[d.size()]-pd[e];
        }
    }
    string o;
    char t[24];
    for(ll x:r){
        int l=0;
        if(!x)t[l++]='0';
        while(x){t[l++]='0'+x%10;x/=10;}
        while(l)o+=t[--l];
        o+='\n';
    }
    fwrite(o.data(),1,o.size(),stdout);
}