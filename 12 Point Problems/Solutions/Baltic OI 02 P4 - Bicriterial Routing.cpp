#include <bits/stdc++.h>
using namespace std;

const int I=1000000000,K=100;

template<class T>
int sz(const T &x){ return x.size(); }

int md(int a,int b){ a%=b; if(a<0)a+=b; return a; }

template<class T>
class RA{
    T *p;
    int X,Y;
public:
    RA(int x,int y):X(x),Y(y){ p=new T[x*y]; }
    ~RA(){ delete[] p; }
    T &operator()(int x,int y){ return p[x+md(y,Y)*X]; }
};

struct E{ int f,t,tm,c; };

int n,s,e;
vector<E> nz;
vector<vector<E>> z;

void rd(){
    int m;
    cin>>n>>m>>s>>e;
    --s; --e;
    z.assign(n,vector<E>());
    for(int i=0;i<m;++i){
        E x; cin>>x.f>>x.t>>x.tm>>x.c;
        --x.f; --x.t;
        if(x.tm) nz.push_back(x);
        else z[x.f].push_back(x);
        swap(x.f,x.t);
        if(x.tm) nz.push_back(x);
        else z[x.f].push_back(x);
    }
}

void upd(RA<int> &t,int k){
    for(int i=0;i<sz(nz);++i){
        E x=nz[i];
        t(x.t,k)=min(t(x.t,k),t(x.f,k-x.tm)+x.c);
    }
}

namespace DIJ{
    vector<int> d,h,inh;

    int szH(){ return sz(h)-1; }

    void sw(int a,int b){ swap(h[a],h[b]); inh[h[a]]=a; inh[h[b]]=b; }

    void up(int p){ while(p>1 && d[h[p>>1]]>d[h[p]]){ sw(p,p>>1); p>>=1; } }

    void dn(int p){
        int s=szH();
        for(;;){
            p<<=1;
            if(p+1<=s && d[h[p+1]]<d[h[p]]) ++p;
            if(p>s || d[h[p>>1]]<=d[h[p]]) break;
            sw(p,p>>1);
        }
    }

    int ext(){
        int x=h[1];
        sw(1,szH());
        inh[x]=-1;
        h.pop_back();
        if(!h.empty()) dn(1);
        return x;
    }

    void dij(RA<int> &t,int k){
        d.resize(n);
        for(int i=0;i<n;++i) d[i]=t(i,k);
        h.resize(n+1); inh.resize(n);
        for(int i=0;i<n;++i){ h[i+1]=i; inh[i]=i+1; }
        for(int i=n;i>=1;--i) dn(i);
        while(szH()>0){
            int x=ext();
            for(int i=0;i<sz(z[x]);++i){
                E y=z[x][i];
                d[y.t]=min(d[y.t],d[x]+y.c);
                if(inh[y.t]!=-1) up(inh[y.t]);
            }
        }
        for(int i=0;i<n;++i) t(i,k)=d[i];
    }
} using DIJ::dij;

int comp(){
    RA<int> t(n,K+1);
    for(int k=-K;k<=0;++k) for(int i=0;i<n;++i) t(i,k)=I;
    t(s,0)=0;
    dij(t,0);
    int r=0,f=t(e,0);
    if(f<I) ++r;
    for(int k=1;k<=n*K;++k){
        for(int i=0;i<n;++i) t(i,k)=I;
        upd(t,k);
        dij(t,k);
        if(t(e,k)<f){ f=t(e,k); ++r; }
    }
    return r;
}

int main(){
    rd();
    cout<<comp()<<"\n";
}