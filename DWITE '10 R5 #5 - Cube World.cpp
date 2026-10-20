#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2){
        vector<vector<int>>h(n,vector<int>(m));
        for(auto&r:h)for(auto&x:r)scanf("%d",&x);
        vector<vector<char>>v(n,vector<char>(m,0));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>>q;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!i||!j||i==n-1||j==m-1){v[i][j]=1;q.push({h[i][j],i,j});}
        int r=0,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
        while(!q.empty()){
            auto[w,x,y]=q.top();q.pop();
            for(int d=0;d<4;d++){
                int a=x+dx[d],b=y+dy[d];
                if(a<0||b<0||a>=n||b>=m||v[a][b])continue;
                v[a][b]=1;r+=max(0,w-h[a][b]);q.push({max(w,h[a][b]),a,b});
            }
        }
        printf("%d\n",r);
    }
}
