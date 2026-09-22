#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
mt19937 rnd;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    if(a[0]!=-1){
        int m=min(n,4);
        for(int i=1;i<(1<<m)-1;i++){
            for(int j=1;j<(1<<m)-1;j++){
                if(i&j) continue;
                ll s1=0,s2=0;
                for(int k=0;k<m;k++){
                    if(i&(1<<k)) s1+=a[k];
                    if(j&(1<<k)) s2+=a[k];
                }
                if(gcd(s1,s2)>1){
                    cout<<"YES\n"<<__builtin_popcount(i)<<' '<<__builtin_popcount(j)<<'\n';
                    vector<int> v;
                    for(int mask:{i,j}){
                        for(int k=0;k<m;k++) if(mask&(1<<k)) v.push_back(k);
                        for(int k=0;k<v.size();k++) cout<<v[k]+1<<" \n"[k+1==v.size()];
                        v.clear();
                    }
                    return 0;
                }
            }
        }
        cout<<"NO\n";
    } else {
        vector<int> v(n);
        iota(v.begin(),v.end(),0);
        shuffle(v.begin(),v.end(),rnd);
        cout<<"100\n";
        for(int i=0;i<100;i++){
            cout<<"2 2\n"<<v[4*i]<<' '<<v[4*i+1]<<'\n'<<v[4*i+2]<<' '<<v[4*i+3]<<'\n';
        }
    }
}