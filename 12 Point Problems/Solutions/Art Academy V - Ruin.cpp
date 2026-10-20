#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll I=(ll)4e18;
int m;
ll X[100005],Y[100005];
int id[100005],ps[100005];
struct N{int l,r,a,b;ll x1,x2,y1,y2,v;};
vector<N> t;
int bd(int l,int r){
    int k=t.size();
    t.push_back({-1,-1,l,r,I,-I,I,-I,I});
    ll a1=I,a2=-I,b1=I,b2=-I;
    for(int i=l;i<r;i++){int j=id[i];a1=min(a1,X[j]);a2=max(a2,X[j]);b1=min(b1,Y[j]);b2=max(b2,Y[j]);}
    t[k].x1=a1;t[k].x2=a2;t[k].y1=b1;t[k].y2=b2;
    if(r-l>1){
        int h=(l+r)/2;
        bool ax=a2-a1>=b2-b1;
        nth_element(id+l,id+h,id+r,[&](int p,int q){return ax?X[p]<X[q]:Y[p]<Y[q];});
        int L=bd(l,h),R=bd(h,r);
        t[k].l=L;t[k].r=R;
    }
    return k;
}
void up(int k,int p,ll v){
    while(1){
        if(v<t[k].v)t[k].v=v;
        if(t[k].l<0)break;
        int h=(t[k].a+t[k].b)/2;
        k=p<h?t[k].l:t[k].r;
    }
}
ll qx,qy,bs;
ll lb(int k){
    if(t[k].v>=I)return I;
    ll d=0;
    if(qx<t[k].x1)d+=t[k].x1-qx;else if(qx>t[k].x2)d+=qx-t[k].x2;
    if(qy<t[k].y1)d+=t[k].y1-qy;else if(qy>t[k].y2)d+=qy-t[k].y2;
    return t[k].v+d;
}
void qu(int k){
    if(lb(k)>=bs)return;
    if(t[k].l<0){
        int j=id[t[k].a];
        ll d=(X[j]>qx?X[j]-qx:qx-X[j])+(Y[j]>qy?Y[j]-qy:qy-Y[j]);
        if(t[k].v+d<bs)bs=t[k].v+d;
        return;
    }
    ll a=lb(t[k].l),b=lb(t[k].r);
    if(a<=b){qu(t[k].l);if(lb(t[k].r)<bs)qu(t[k].r);}
    else{qu(t[k].r);if(lb(t[k].l)<bs)qu(t[k].l);}
}
int main(){
    int n;
    scanf("%d",&n);
    ll p,q,r,s;
    scanf("%lld %lld %lld %lld",&p,&q,&r,&s);
    vector<ll>ax(n),ay(n);
    for(int i=0;i<n;i++)scanf("%lld %lld",&ax[i],&ay[i]);
    m=n+2;
    X[0]=p;Y[0]=q;X[1]=r;Y[1]=s;
    for(int i=0;i<n;i++){X[2+i]=ax[i];Y[2+i]=ay[i];}
    for(int i=0;i<m;i++)id[i]=i;
    t.reserve(2*m+2);
    bd(0,m);
    for(int i=0;i<m;i++)ps[id[i]]=i;
    ll d1=(p>ax[0]?p-ax[0]:ax[0]-p)+(q>ay[0]?q-ay[0]:ay[0]-q);
    ll d2=(r>ax[0]?r-ax[0]:ax[0]-r)+(s>ay[0]?s-ay[0]:ay[0]-s);
    up(0,ps[1],d1);
    up(0,ps[0],d2);
    ll of=0,mf=min(d1,d2);
    for(int i=0;i+1<n;i++){
        ll D=(ax[i]>ax[i+1]?ax[i]-ax[i+1]:ax[i+1]-ax[i])+(ay[i]>ay[i+1]?ay[i]-ay[i+1]:ay[i+1]-ay[i]);
        qx=ax[i+1];qy=ay[i+1];bs=I;
        qu(0);
        ll nf=bs-D;
        of+=D;
        up(0,ps[2+i],nf);
        if(nf<mf)mf=nf;
    }
    printf("%lld\n",of+mf);
    return 0;
}