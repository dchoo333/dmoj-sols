#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;

struct Rect { int x1, y1, x2, y2; } r[MAXN];

struct Edge { int to, cost; Edge(int t,int c):to(t),cost(c){} };
bool operator<(const Edge &a, const Edge &b){ return a.cost>b.cost; }

int n;
int px[MAXN*4], py[MAXN*4], ind[MAXN*4];
vector<Edge> adj[MAXN*8];
int dist[MAXN*8];

bool is_inside(int x,int y){
    for(int i=0;i<n;i++)
        if(x>r[i].x1 && x<r[i].x2 && y>r[i].y1 && y<r[i].y2)
            return true;
    return false;
}

bool cmpx(int a,int b){ return px[a]<px[b]; }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;

    int X=r[0].x1, Y=r[0].y1;
    sort(r,r+n,[](Rect &a,Rect &b){ return a.x1<b.x1; });

    int N=0;
    for(int i=0;i<n;i++){
        if(!is_inside(r[i].x1,r[i].y1)){ px[N]=r[i].x1; py[N++]=r[i].y1; }
        if(!is_inside(r[i].x2,r[i].y1)){ px[N]=r[i].x2; py[N++]=r[i].y1; }
        if(!is_inside(r[i].x1,r[i].y2)){ px[N]=r[i].x1; py[N++]=r[i].y2; }
        if(!is_inside(r[i].x2,r[i].y2)){ px[N]=r[i].x2; py[N++]=r[i].y2; }
    }

    for(int i=0;i<N;i++) ind[i]=i;
    sort(ind,ind+N,cmpx);

    for(int ii=0;ii<N;ii++){
        int i=ind[ii];
        int j=0, miny=0, maxy=10000;
        while(j<n && r[j].x1<px[i]){
            if(r[j].x2>px[i]){
                if(r[j].y1<py[i] && r[j].y2>py[i]) assert(0);
                if(r[j].y1>=py[i]) maxy=min(maxy,r[j].y1);
                else if(r[j].y2<=py[i]) miny=max(miny,r[j].y2);
            }
            j++;
        }
        for(int jj=ii+1;jj<N;jj++){
            int k=ind[jj];
            while(j<n && r[j].x1<px[k]){
                if(r[j].y1<py[i] && r[j].y2>py[i]) { miny=r[j].y2; maxy=r[j].y1; }
                else if(r[j].y1>=py[i]) maxy=min(maxy,r[j].y1);
                else if(r[j].y2<=py[i]) miny=max(miny,r[j].y2);
                j++;
            }
            if(maxy<miny) break;
            if(py[k]>=miny && py[k]<=maxy){
                int from=i, to=k;
                int len=abs(px[to]-px[from])+abs(py[to]-py[from]);
                if(px[from]<=X && px[to]>X && py[from]<=Y && py[to]<=Y){
                    adj[from].push_back(Edge(to+N,len));
                    adj[from+N].push_back(Edge(to,len));
                    adj[to].push_back(Edge(from+N,len));
                    adj[to+N].push_back(Edge(from,len));
                } else {
                    adj[from].push_back(Edge(to,len));
                    adj[from+N].push_back(Edge(to+N,len));
                    adj[to].push_back(Edge(from,len));
                    adj[to+N].push_back(Edge(from+N,len));
                }
            }
        }
    }

    const int INF = 2e9;
    int best = INF;

    for(int i=0;i<N;i++){
        fill(dist, dist+2*N, INF);
        priority_queue<Edge> Q;
        Q.push(Edge(i,0));
        dist[i]=0;
        while(!Q.empty()){
            Edge e=Q.top(); Q.pop();
            if(e.cost>=best) break;
            if(e.to==i+N){ best=e.cost; break; }
            if(e.cost>dist[e.to]) continue;
            for(Edge &next: adj[e.to]){
                if(e.cost+next.cost<dist[next.to]){
                    dist[next.to]=e.cost+next.cost;
                    Q.push(Edge(next.to, dist[next.to]));
                }
            }
        }
    }

    cout << best << "\n";
    return 0;
}