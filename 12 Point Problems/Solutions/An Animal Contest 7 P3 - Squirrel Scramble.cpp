#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m;

    vector<long long> p(m);
    for(long long i=0;i<m;i++){
        cin>>p[i];
        p[i]--;
    }
    sort(p.begin(),p.end());

    vector<long long>a(n-1);
    for(long long i=0;i<n-1;i++) cin>>a[i];

    vector<long long>pr(n);
    for(long long i=1;i<n;i++) pr[i]=pr[i-1]+a[i-1];

    vector<long long>d(n,LLONG_MAX);
    for(long long i=0;i<n;i++){
        long long lo=lower_bound(p.begin(),p.end(),i)-p.begin();
        long long b=LLONG_MAX;
        if(lo<m) b=min(b,pr[p[lo]]-pr[i]);
        if(lo>0) b=min(b,pr[i]-pr[p[lo-1]]);
        d[i]=b;
    }
    for(long long x:p) d[x]=0;

    vector<long long>R(n),L(n);
    for(long long i=0;i<n;i++){
        R[i]=pr[i]+d[i];
        L[i]=pr[i]-d[i];
    }

    vector<long long>s=R;
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    long long z=s.size();

    vector<long long>bc(z+2),bp(z+2),bd(z+2);

    long long ans=0;

    for(long long j=0;j<n;j++){
        long long lb=lower_bound(s.begin(),s.end(),L[j])-s.begin()+1;

        long long tc=0,tp=0,td=0;
        for(long long x=z;x>0;x-=x&-x){
            tc+=bc[x];
            tp=(tp+bp[x])%1000000007;
            td=(td+bd[x])%1000000007;
        }

        long long bc2=0,bp2=0,bd2=0;
        for(long long x=lb-1;x>0;x-=x&-x){
            bc2+=bc[x];
            bp2=(bp2+bp[x])%1000000007;
            bd2=(bd2+bd[x])%1000000007;
        }

        long long ac=tc-bc2;
        long long ap=(tp-bp2+1000000007)%1000000007;

        long long c1=(ac%1000000007*(pr[j]%1000000007)%1000000007-ap+1000000007)%1000000007;
        long long c2=(bd2+bc2%1000000007*(d[j]%1000000007)%1000000007)%1000000007;

        ans=(ans+c1+c2)%1000000007;

        long long id=lower_bound(s.begin(),s.end(),R[j])-s.begin()+1;
        for(long long x=id;x<=z;x+=x&-x){
            bc[x]++;
            bp[x]=(bp[x]+pr[j])%1000000007;
            bd[x]=(bd[x]+d[j])%1000000007;
        }
    }

    cout<<ans<<"\n";
}
