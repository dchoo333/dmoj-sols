#include <bits/stdc++.h>
using namespace std;
#define MX 2001
char g[MX][MX];
struct P{int x,y;};
queue<P> Q;
int m[MX][MX], r, c, i, j, k, nx, ny, d;
int mv[4][3]={{1,0,0},{0,1,1},{0,-1,2},{-1,0,3}};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for(i=0;i<r;i++) for(j=0;j<c;j++) cin >> g[i][j];
    for(j=0;j<c;j++) if(g[0][j]=='#'){ m[0][j]=MX; Q.push({0,j}); }
    while(!Q.empty()){
        P p=Q.front(); Q.pop();
        i=p.x; j=p.y;
        for(k=0;k<4;k++){
            nx=i+mv[k][0]; ny=j+mv[k][1]; d=mv[k][2];
            if(nx<0||nx>=r||ny<0||ny>=c) continue;
            if(g[nx][ny]=='#'){
                if(m[nx][ny]>=m[i][j]) continue;
                m[nx][ny]=m[i][j]; Q.push({nx,ny});
            } else {
                int cnt=0, tx=nx, ty=ny;
                while(tx>=0&&tx<r&&ty>=0&&ty<c&&g[tx][ty]=='.'){ cnt++; tx+=mv[d][0]; ty+=mv[d][1]; }
                if(tx>=0&&tx<r&&ty>=0&&ty<c&&m[tx][ty]<min(cnt,m[i][j])){
                    m[tx][ty]=min(cnt,m[i][j]); Q.push({tx,ty});
                }
            }
        }
    }
    for(j=0;j<c;j++){
        int v=m[r-1][j];
        cout<<(v==0?-1:(v==MX?0:v))<<(j<c-1?' ':'\n');
    }
}