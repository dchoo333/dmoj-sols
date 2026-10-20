#include <bits/stdc++.h>
using namespace std;

vector<int> sa_build(const string& s){
    int n=s.size();
    vector<int> sa(n),r(n),t(n);
    iota(sa.begin(),sa.end(),0);
    for(int i=0;i<n;i++) r[i]=s[i];
    for(int g=1;g<n;g<<=1){
        auto c=[&](int a,int b){
            if(r[a]!=r[b]) return r[a]<r[b];
            int ra=a+g<n?r[a+g]:-1;
            int rb=b+g<n?r[b+g]:-1;
            return ra<rb;
        };
        sort(sa.begin(),sa.end(),c);
        t[sa[0]]=0;
        for(int i=1;i<n;i++) t[sa[i]]=t[sa[i-1]]+(c(sa[i-1],sa[i])?1:0);
        r=t;
        if(r[sa[n-1]]==n-1) break;
    }
    return sa;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    int n=s.size();

    vector<int> sa=sa_build(s);

    int L=1;
    while((1<<L)<=n) L++;

    vector<vector<int>> tr(L,vector<int>(n));
    vector<vector<int>> ct(L,vector<int>(n+1));

    tr[0]=sa;

    for(int j=0;j<L-1;j++){
        for(int i=0;i<n;i++) ct[j][i+1]=ct[j][i]+(!(tr[j][i]&(1<<(L-1-j))));
        vector<int> l,r;
        for(int i=0;i<n;i++)
            (tr[j][i]&(1<<(L-1-j))?r:l).push_back(tr[j][i]);
        int id=0;
        for(int x:l) tr[j+1][id++]=x;
        for(int x:r) tr[j+1][id++]=x;
    }

    int j=L-1;
    for(int i=0;i<n;i++) ct[j][i+1]=ct[j][i]+(!(tr[j][i]&1));

    auto kth=[&](int l,int r,int k){
        int v=0;
        for(int j=0;j<L;j++){
            int lb=ct[j][l],rb=ct[j][r+1];
            int in=rb-lb;
            if(k<=in){
                r=lb+in-1;
                l=lb;
            }else{
                v|=(1<<(L-1-j));
                k-=in;
                int tl=ct[j][n];
                int nl=tl+l-lb;
                int nr=tl+r-rb;
                l=nl;
                r=nr;
            }
        }
        return v;
    };

    auto fr=[&](const string& t){
        int tl=t.size(),lo=0,hi=n;
        while(lo<hi){
            int m=(lo+hi)/2;
            int sf=sa[m];
            int cl=min(tl,n-sf);
            int c=s.compare(sf,cl,t,0,cl);
            if(c<0||(c==0&&n-sf<tl)) lo=m+1;
            else hi=m;
        }
        int lb=lo;
        hi=n;
        while(lo<hi){
            int m=(lo+hi)/2;
            int sf=sa[m];
            int cl=min(tl,n-sf);
            int c=s.compare(sf,cl,t,0,cl);
            if(c==0&&n-sf>=tl) lo=m+1;
            else hi=m;
        }
        return pair<int,int>(lb,lo);
    };

    int q;
    cin>>q;

    while(q--){
        string t;
        int k;
        cin>>t>>k;

        auto [l,r]=fr(t);
        int c=r-l;

        if(k>c) cout<<-1<<"\n";
        else{
            int p=kth(l,r-1,k);
            cout<<p+1<<"\n";
        }
    }
}