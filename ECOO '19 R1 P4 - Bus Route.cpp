#include <bits/stdc++.h>
using namespace std;

int a,b,n,m,c,x[500005],s[500005];
vector<int> v[500005];
map<int,int> o[500005];
set<pair<int,int>> f,g;

int main(){
    for(int z=0;z<10;z++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear(),o[i].clear();
        c=m/40+10;
        f.clear();
        for(int i=1;i<=c;i++){
            x[i]=i*10;
            s[i]=40;
            f.insert({x[i],i});
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            g.clear();
            a=v[i].size();
            for(auto &j:f){
                if(a<=0) break;
                g.insert(j);
                a-=s[j.second];
            }
            for(auto &j:o[i]) g.insert({x[j.first],j.first});
            reverse(v[i].begin(),v[i].end());
            for(auto &j:g){
                int d=0;
                if(f.count(j)) f.erase(j);
                if(o[i].count(j.second)){
                    s[j.second]+=o[i][j.second];
                    d=1;
                }
                while(s[j.second] && !v[i].empty()){
                    s[j.second]--;
                    o[v[i].back()][j.second]++;
                    v[i].pop_back();
                    d=1;
                }
                if(d) x[j.second]++;
                if(s[j.second]) f.insert({x[j.second],j.second});
            }
        }
        int r=1;
        for(int i=2;i<=c;i++) if(x[r]>x[i]) r=i;
        printf("Bus #%d\n",r);
    }
}