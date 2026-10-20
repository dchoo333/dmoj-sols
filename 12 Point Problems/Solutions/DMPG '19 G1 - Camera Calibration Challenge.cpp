#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll W = 1000000000000LL;

static char buf[1<<25]; static int bp=0, bl=0;
static inline int gc(){ if(bp==bl){ bl=(int)fread(buf,1,sizeof(buf),stdin); bp=0; if(bl<=0) return -1;} return buf[bp++]; }
static inline ll rd(){ int c=gc(); while(c!=-1&&(c<'0'||c>'9')) c=gc(); ll x=0; while(c>='0'&&c<='9'){ x=x*10+(c-'0'); c=gc(); } return x; }

int main(){
    ll n=rd(), m=rd();
    ll K=n*m;
    vector<int> b(K);
    for(ll i=0;i<K;i++) b[i]=(int)rd();
    sort(b.begin(), b.end(), greater<int>());

    int Q=(int)rd();
    vector<ll> e(Q); vector<int> ord(Q);
    for(int i=0;i<Q;i++){ e[i]=rd(); ord[i]=i; }
    sort(ord.begin(), ord.end(), [&](int x,int y){ return e[x]<e[y]; });

    ll total=0; for(ll i=0;i<K;i++) total+=b[i];

    vector<ll> ans(Q);
    ll c=0, sn=total, C=0;
    for(int qi=0; qi<Q; qi++){
        int id=ord[qi];
        ll T = K * e[id] * 1000000LL;
        while(true){
            ll rem = T - c*W;
            ll need = (rem<=0 || sn==0) ? 0 : (rem + sn - 1)/sn;
            if(need>C) C=need;
            if(c<K && (__int128)C*b[c] >= W){ sn-=b[c]; c++; continue; }
            break;
        }
        ans[id]=C;
    }

    string out; out.reserve((size_t)Q*14);
    for(int i=0;i<Q;i++){ out+=to_string(ans[i]); out+='\n'; }
    fwrite(out.data(),1,out.size(),stdout);
    return 0;
}