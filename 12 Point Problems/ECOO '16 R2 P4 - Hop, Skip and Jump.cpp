#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define x first
#define y second

const int CL=0, LA=1, PT=2;
const int HOP=1, SKIP=2, JUMP=3;
const int CUP=0, FLAG=1, TREASURE=2;

int Col, Row, g[210][210];
bool vis[210][210], sol[3];
queue<pii> Q;
pii C,F,T,H,S,J;
char ch;

void init(){
    memset(g, 0, sizeof(g));
    C=F=T=H=S=J={0,0};
    Col=Row=0;
}

void read(){
    scanf("%d %d", &Col, &Row);
    for(int i=1;i<=Row;i++){
        for(int j=1;j<=Col;j++){
            scanf(" %c", &ch);
            switch(ch){
                case '#': g[i][j]=LA; break;
                case '=': g[i][j]=PT; break;
                case 'C': C={i,j}; break;
                case 'F': F={i,j}; break;
                case 'T': T={i,j}; break;
                case 'h': H={i,j}; break;
                case 's': S={i,j}; break;
                case 'j': J={i,j}; break;
            }
        }
    }
}

void QP(int r,int c){
    if(r>=1 && r<=Row && c>=1 && c<=Col && !vis[r][c] && g[r][c]!=PT){
        Q.push({r,c});
        vis[r][c]=1;
    }
}

string BFS(pii st,int bro){
    string ret="";
    memset(vis,0,sizeof(vis));
    memset(sol,0,sizeof(sol));
    Q.push(st);
    vis[st.x][st.y]=1;
    while(!Q.empty()){
        pii cur=Q.front(); Q.pop();
        if(cur==C) sol[CUP]=1;
        if(cur==F) sol[FLAG]=1;
        if(cur==T) sol[TREASURE]=1;
        int r=cur.x, c=cur.y;
        if(g[r][c]!=LA && !g[r+1][c]) { QP(r+1,c); continue; }
        if(g[r+1][c]==LA) QP(r+1,c);
        if(g[r][c-1]!=PT) QP(r,c-1);
        if(g[r][c+1]!=PT) QP(r,c+1);
        if(g[r][c]==LA){ QP(r-1,c); QP(r+1,c); }
        if(bro==HOP){
            QP(r-1,c); QP(r-1,c-1); QP(r-1,c+1);
        }
        if(bro==SKIP){
            if(g[r][c+1]!=PT) QP(r,c+2);
            if(g[r][c-1]!=PT) QP(r,c-2);
        }
        if(bro==JUMP){
            QP(r-1,c); QP(r-1,c-1); QP(r-1,c+1);
            if(g[r][c+1]!=PT) QP(r,c+2);
            if(g[r][c-1]!=PT) QP(r,c-2);
            if(c>1 && g[r][c-1]!=PT && g[r][c-2]!=PT) QP(r,c-3);
            if(g[r][c+1]!=PT && g[r][c+2]!=PT) QP(r,c+3);
            if(g[r-1][c]!=PT) QP(r-2,c);
            if(g[r-1][c]!=PT && g[r][c+1]!=PT && g[r-1][c+1]!=PT) QP(r-1,c+2);
            if(g[r-1][c]!=PT && g[r][c-1]!=PT && g[r-1][c-1]!=PT) QP(r-1,c-2);
        }
    }
    return ret+(sol[CUP]?"C":"")+(sol[FLAG]?"F":"")+(sol[TREASURE]?"T":"");
}

int main(){
    for(int k=0;k<10;k++){
        init();
        read();
        cout << "HOP " << BFS(H,HOP) << "\n";
        cout << "SKIP " << BFS(S,SKIP) << "\n";
        cout << "JUMP " << BFS(J,JUMP) << "\n";
    }
}