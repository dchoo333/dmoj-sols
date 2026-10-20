#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c;scanf("%d %d",&r,&c);
    vector<string>g(r);
    for(auto&s:g){char b[105];scanf("%s",b);s=b;}
    int M=2*99*99;
    vector<vector<pair<int,int>>>of(M+1);
    for(int a=-99;a<=99;a++)for(int b=-99;b<=99;b++)if(a||b)of[a*a+b*b].push_back({a,b});
    vector<int>xs,ls;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){if(g[i][j]=='X')xs.push_back(i*c+j);else if(g[i][j]=='L')ls.push_back(i*c+j);}
    vector<char>al(r*c,1);
    vector<int>cn(r*c,0);
    int nx=xs.size(),nl=ls.size(),ex=0;
    bool fx=xs.size()<=ls.size();
    auto&sm=fx?xs:ls;
    char ot=fx?'L':'X';
    for(int d=1;d<=M&&nx&&nl;d++){
        if(of[d].empty())continue;
        vector<pair<int,int>>pr;
        for(int s:sm){
            if(!al[s])continue;
            int i=s/c,j=s%c;
            for(auto[a,b]:of[d]){
                int y=i+a,x=j+b;
                if(y<0||y>=r||x<0||x>=c)continue;
                int t=y*c+x;
                if(g[y][x]==ot&&al[t])pr.push_back(fx?make_pair(t,s):make_pair(s,t));
            }
        }
        for(auto&p:pr)cn[p.first]++;
        for(auto&p:pr){
            int l=p.first;
            if(cn[l]>=2)ex++,cn[l]=-1;
        }
        for(auto&p:pr){
            if(al[p.first]){al[p.first]=0;nl--;}
            if(al[p.second]){al[p.second]=0;nx--;}
            cn[p.first]=0;
        }
    }
    printf("%d\n",ex);
}