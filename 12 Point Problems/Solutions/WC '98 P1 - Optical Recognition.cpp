#include <bits/stdc++.h>
using namespace std;
typedef vector<string> Grid;

Grid rni(const Grid &g){                    
    int H=g.size(), W=g[0].size();
    Grid r(W, string(H,'o'));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) r[j][H-1-i]=g[i][j];
    return r;
}
Grid suu(const Grid &g,int k){
    Grid r;
    for(const string &row: g){ string s; for(char c: row) s.append(k,c); for(int t=0;t<k;t++) r.push_back(s); }
    return r;
}
Grid trim(const Grid &g){
    int H=g.size(), W=H?g[0].size():0, r1=INT_MAX,r2=-1,c1=INT_MAX,c2=-1;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(g[i][j]=='*'){r1=min(r1,i);r2=max(r2,i);c1=min(c1,j);c2=max(c2,j);}
    Grid o; if(r2<0) return o;
    for(int i=r1;i<=r2;i++) o.push_back(g[i].substr(c1,c2-c1+1));
    return o;
}

map<Grid,char> shapes;  
const int R=21;

int main(){
    ios::sync_with_stdio(false);
    vector<string> all; string line;
    while(getline(cin,line)){
        while(!line.empty() && (line.back()=='\r'||line.back()==' ')) line.pop_back();
        if(line.empty()) continue;
        all.push_back(line);
    }
    size_t p=0;
    for(int L=0;L<5;L++){
        char name=all[p++][0];
        Grid g; for(int i=0;i<7;i++) g.push_back(all[p++]);
        g=trim(g);
        for(int rot=0;rot<4;rot++){
            for(int k=1;k<=3;k++) shapes.emplace(suu(g,k), name);
            g=rni(g);
        }
    }
    for(; p+R<=all.size(); p+=R){
        Grid grid(all.begin()+p, all.begin()+p+R);
        size_t W=0; for(auto&s:grid) W=max(W,s.size());
        for(auto&s:grid) s.resize(W,'o');

        vector<pair<int,int>> runs;              
        for(size_t c=0;c<W;c++){
            bool full=false; for(int r=0;r<R;r++) if(grid[r][c]=='*') full=true;
            if(!full) continue;
            if(!runs.empty() && runs.back().second==(int)c-1) runs.back().second=c;
            else runs.push_back({(int)c,(int)c});
        }
        if(runs.empty()){ printf("EMPTY\n"); continue; }

        string word; bool ok=true;
        for(size_t i=0;i<runs.size() && ok;){
            bool matched=false;
            for(size_t j=i;j<runs.size() && j<i+4 && !matched;j++){
                int c1=runs[i].first, c2=runs[j].second;
                Grid sub; for(int r=0;r<R;r++) sub.push_back(grid[r].substr(c1,c2-c1+1));
                auto it=shapes.find(trim(sub));
                if(it!=shapes.end()){ word+=it->second; i=j+1; matched=true; }
            }
            if(!matched) ok=false;
        }
        printf("%s\n", ok? word.c_str() : "NONE");
    }
}