#include<bits/stdc++.h>
using namespace std;
int H=10,W=9,n;
char g[10][9],ch[12];
vector<vector<pair<int,int>>>p;
bool u[12];
bool go(int k){
    if(k==n)return 1;
    int a=-1,b=-1;
    for(int i=0;i<H&&a<0;i++)for(int j=0;j<W;j++)if(!g[i][j]){a=i;b=j;break;}
    if(a<0)return 0;
    for(int i=0;i<n;i++){
        if(u[i])continue;
        bool o=1;
        for(auto&d:p[i]){
            int r=a+d.first,c=b+d.second;
            if(r<0||r>=H||c<0||c>=W||g[r][c]){o=0;break;}
        }
        if(!o)continue;
        for(auto&d:p[i])g[a+d.first][b+d.second]=ch[i];
        u[i]=1;
        if(go(k+1))return 1;
        u[i]=0;
        for(auto&d:p[i])g[a+d.first][b+d.second]=0;
    }
    return 0;
}
int main(){
    vector<string>L;
    string s;
    while(getline(cin,s)){
        while(s.size()&&(s.back()=='\r'||s.back()=='\n'))s.pop_back();
        L.push_back(s);
    }
    size_t x=0;
    while(x<L.size()&&L[x].find_first_not_of(' ')==string::npos)x++;
    int t=stoi(L[x++]);
    while(t--){
        while(x<L.size()&&L[x].find_first_not_of(' ')==string::npos)x++;
        n=stoi(L[x++]);
        p.assign(n,{});
        for(int i=0;i<n;i++){
            vector<string>m;
            while(x<L.size()){
                string&q=L[x];
                size_t f=q.find_first_not_of(' ');
                if(f!=string::npos&&q[f]=='0'&&q.find_first_not_of(" 0")==string::npos){x++;break;}
                m.push_back(q);
                x++;
            }
            int ar=-1,ac=-1;
            for(int r=0;r<(int)m.size()&&ar<0;r++)for(int c=0;c<(int)m[r].size();c++)if(m[r][c]!=' '){ar=r;ac=c;ch[i]=m[r][c];break;}
            for(int r=0;r<(int)m.size();r++)for(int c=0;c<(int)m[r].size();c++)if(m[r][c]!=' ')p[i].push_back({r-ar,c-ac});
        }
        memset(g,0,sizeof g);
        memset(u,0,sizeof u);
        go(0);
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++)putchar(g[i][j]?g[i][j]:' ');
            putchar('\n');
        }
    }
    return 0;
}