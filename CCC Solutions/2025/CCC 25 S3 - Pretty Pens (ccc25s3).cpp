#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,q,a[200001],b[200001],ts=0;
set<pair<int,int>,greater<pair<int,int>>> C[200001];
set<pair<int,int>> R1,R2;
pair<int,int> t1,t2;

signed main(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) C[i].insert({0,0});
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        a[i]=x; b[i]=y;
        C[x].insert(make_pair(y,i));
    }
    for(int i=1;i<=m;i++){
        t1=*C[i].begin(); t2=*(++C[i].begin());
        ts+=t1.first;
        R1.insert(t1); R2.insert(t2);
    }
    cout<<max(ts,ts+(--R2.end())->first - R1.begin()->first)<<endl;
    while(q--){
        int ty,idv,x; cin>>ty>>idv>>x;
        int loc=a[idv],val=b[idv];
        if(ty==1){
            t1=*C[loc].begin(); t2=*(++C[loc].begin());
            R1.erase(t1); R2.erase(t2); ts-=t1.first;
            t1=*C[x].begin(); t2=*(++C[x].begin());
            R1.erase(t1); R2.erase(t2); ts-=t1.first;
            C[loc].erase(make_pair(val,idv)); C[x].insert(make_pair(val,idv));
            a[idv]=x;
            t1=*C[loc].begin(); t2=*(++C[loc].begin());
            R1.insert(t1); R2.insert(t2); ts+=t1.first;
            t1=*C[x].begin(); t2=*(++C[x].begin());
            R1.insert(t1); R2.insert(t2); ts+=t1.first;
        }else{
            t1=*C[loc].begin(); t2=*(++C[loc].begin());
            R1.erase(t1); R2.erase(t2); ts-=t1.first;
            C[loc].erase(make_pair(val,idv)); C[loc].insert(make_pair(x,idv));
            b[idv]=x;
            t1=*C[loc].begin(); t2=*(++C[loc].begin());
            R1.insert(t1); R2.insert(t2); ts+=t1.first;
        }
        cout<<max(ts,ts+(--R2.end())->first - R1.begin()->first)<<endl;
    }
}
