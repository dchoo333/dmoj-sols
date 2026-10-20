#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int s;scanf("%d",&s);
        vector<pair<int,int>>p(s);
        for(auto&q:p){int x,y;scanf("%d - %d",&x,&y);q={min(x,y),max(x,y)};}
        sort(p.begin(),p.end());
        vector<vector<pair<int,int>>>g;
        multiset<pair<int,int>>m;
        for(auto&q:p){
            auto it=m.upper_bound({q.second,INT_MAX});
            int k;
            if(it==m.begin()){k=g.size();g.push_back({});}
            else{--it;k=it->second;m.erase(it);}
            g[k].push_back(q);
            m.insert({q.second,k});
        }
        printf("%d\n",(int)g.size());
        for(auto&v:g){
            for(int i=0;i<(int)v.size();i++)printf("%s%d-%d",i?" ":"",v[i].second,v[i].first);
            printf("\n");
        }
    }
}