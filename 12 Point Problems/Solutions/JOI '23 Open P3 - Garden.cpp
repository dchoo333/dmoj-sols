#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,D; cin>>N>>M>>D;

    vector<int>P(N),Q(N);
    for(int i=0;i<N;i++) cin>>P[i]>>Q[i];

    vector<int>R(M),S(M);
    for(int i=0;i<M;i++) cin>>R[i]>>S[i];

    vector<int>cQ(D),cP(D);
    for(int i=0;i<N;i++) cQ[Q[i]]++;
    for(int i=0;i<N;i++) cP[P[i]]++;

    int tp=0;
    for(int i=0;i<D;i++) if(cP[i]) tp++;

    vector<vector<int>> rv(D);
    {
        vector<set<int>> s(D);
        for(int i=0;i<M;i++) s[S[i]].insert(R[i]);
        for(int i=0;i<D;i++) rv[i]=vector<int>(s[i].begin(),s[i].end());
    }

    vector<vector<int>> rx(D);
    for(int i=0;i<D;i++) for(int x:rv[i]) rx[x].push_back(i);

    vector<vector<int>> ev(D);
    vector<int> ep(D,-1),pt(D,-1);

    auto rem=[&](int y){
        int cr=rv[y][pt[y]];
        int ps=ep[y];
        auto &v=ev[cr];
        int ly=v.back();
        v[ps]=ly;
        ep[ly]=ps;
        v.pop_back();
        ep[y]=-1;
    };
    auto add=[&](int y,int cr){
        ep[y]=ev[cr].size();
        ev[cr].push_back(y);
    };

    for(int i=0;i<D;i++) if(!rv[i].empty()){
        pt[i]=rv[i].size()-1;
        add(i,rv[i][pt[i]]);
    }

    vector<int> md;
    for(int i=0;i<D;i++) if(cQ[i]||!rv[i].empty()) md.push_back(i);
    int K=md.size();

    vector<int> nx(D),pr(D);
    vector<bool> in(D);
    int hd=-1,ct=0,mg=0;

    auto gp=[&](int a,int b){
        int g=(b-a+D)%D;
        return g?g:D;
    };

    auto build=[&](){
        ct=K;
        hd=K?md[0]:-1;
        for(int i=0;i<K;i++){
            int y=md[i];
            in[y]=1;
            nx[y]=md[(i+1)%K];
            pr[y]=md[(i-1+K)%K];
        }
        mg=0;
        if(K){
            int u=hd;
            do{
                int g=gp(u,nx[u]);
                if(g>mg) mg=g;
                u=nx[u];
            }while(u!=hd);
        } else mg=D;
    };

    auto rm=[&](int y){
        int a=pr[y],b=nx[y];
        nx[a]=b; pr[b]=a;
        in[y]=0; ct--;
        int g=gp(a,b);
        if(g>mg) mg=g;
        if(y==hd) hd=ct?b:-1;
    };

    auto mc=[&](){ if(ct<=1) return 1; return D-mg+1; };

    vector<bool> wr(D);
    vector<int> rl;

    build();

    ll ans=(ll)D*D;

    for(int a=0;a<D;a++){
        if(!rl.empty()){
            for(int y:rl){ in[y]=1; wr[y]=0; }
            rl.clear();
            ct=K;
            hd=K?md[0]:-1;
            for(int i=0;i<K;i++){
                int y=md[i];
                nx[y]=md[(i+1)%K];
                pr[y]=md[(i-1+K)%K];
            }
            mg=0;
            if(K){
                int u=hd;
                do{
                    int g=gp(u,nx[u]);
                    if(g>mg) mg=g;
                    u=nx[u];
                }while(u!=hd);
            } else mg=D;
        }

        int up=tp;

        for(int w=1;w<=D;w++){
            int x=(a+w-1)%D;
            if(cP[x]) up--;

            for(int y:ev[x]){
                if(!wr[y]&&cQ[y]==0&&in[y]){
                    rm(y);
                    wr[y]=1;
                    rl.push_back(y);
                }
            }

            if(up==0){
                ll c=(ll)w*mc();
                if(c<ans) ans=c;
            }
        }

        for(int y:rx[a]){
            rem(y);
            int id=lower_bound(rv[y].begin(),rv[y].end(),a)-rv[y].begin();
            pt[y]=id;
            add(y,a);
        }
    }

    cout<<ans<<"\n";
}