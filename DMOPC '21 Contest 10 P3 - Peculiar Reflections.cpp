#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d %d",&n,&m);
    vector<string>g(n);static char b[1000005];
    for(auto&s:g){scanf("%s",b);s=b;}
    int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
    vector<int>D((size_t)n*m*4,INT_MAX);
    deque<int>q;D[2]=0;q.push_back(2);
    int best=INT_MAX;
    while(!q.empty()){
        int s=q.front();q.pop_front();
        int cell=s>>2,d=s&3,r=cell/m,c=cell%m,cd=D[s];
        for(int mi=0;mi<2;mi++){
            int w=cd+((mi==0)!=(g[r][c]=='\\'));
            int o=mi==0?3-d:d^1;
            if(r==n-1&&c==m-1&&o==2){best=min(best,w);continue;}
            int nr=r+dr[o],nc=c+dc[o];
            if(nr<0||nc<0||nr>=n||nc>=m)continue;
            int t=(nr*m+nc)*4+o;
            if(w<D[t]){D[t]=w;if(w==cd)q.push_front(t);else q.push_back(t);}
        }
    }
    printf("%d\n",best==INT_MAX?-1:best);
}