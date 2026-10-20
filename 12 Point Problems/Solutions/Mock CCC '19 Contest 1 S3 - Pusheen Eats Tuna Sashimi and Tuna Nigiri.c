#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXXY 101
#define MAXV 15
#define VSIZE (2*MAXV+1)
#define VOFF MAXV

int X, Y, N;
char wind[MAXXY][MAXXY];
short dist_arr[MAXXY][MAXXY][VSIZE][VSIZE];

typedef struct { short x,y,vx,vy; } State;

State *queue;
int qcap, qhead, qtail;

void enqueue(int x, int y, int vx, int vy) {
    if (qtail >= qcap) {
        qcap *= 2;
        queue = realloc(queue, qcap * sizeof(State));
    }
    queue[qtail++] = (State){(short)x,(short)y,(short)vx,(short)vy};
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int segment_blocked(int x1, int y1, int x2, int y2) {
    int dx = x2-x1, dy = y2-y1;
    if (dx==0 && dy==0) return wind[x1][y1];
    int adx = dx<0?-dx:dx, ady = dy<0?-dy:dy;
    int g = gcd(adx, ady);
    int sx = dx/g, sy = dy/g;
    for (int k=0; k<=g; k++) {
        if (wind[x1+k*sx][y1+k*sy]) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d %d", &X, &Y, &N);
    int xs,ys,xe,ye;
    scanf("%d %d", &xs, &ys);
    scanf("%d %d", &xe, &ye);
    for (int i=0;i<N;i++) {
        int wx,wy; scanf("%d %d",&wx,&wy);
        wind[wx][wy]=1;
    }
    
    memset(dist_arr,-1,sizeof(dist_arr));
    
    qcap = 1<<20;
    qhead = qtail = 0;
    queue = malloc(qcap * sizeof(State));
    
    enqueue(xs,ys,0,0);
    dist_arr[xs][ys][VOFF][VOFF]=0;
    
    int dax[] = {0,1,-1,0,0};
    int day[] = {0,0,0,1,-1};
    
    while (qhead < qtail) {
        State s = queue[qhead++];
        int d = dist_arr[s.x][s.y][s.vx+VOFF][s.vy+VOFF];
        
        if (s.x==xe && s.y==ye && s.vx==0 && s.vy==0) {
            printf("%d\n", d);
            return 0;
        }
        
        for (int m=0;m<5;m++) {
            int nvx = s.vx + dax[m];
            int nvy = s.vy + day[m];
            if (nvx<-MAXV||nvx>MAXV||nvy<-MAXV||nvy>MAXV) continue;
            int nx = s.x + nvx;
            int ny = s.y + nvy;
            if (nx<0||nx>X||ny<0||ny>Y) continue;
            
            if (nvx>0 && nx + nvx*(nvx-1)/2 > X) continue;
            if (nvx<0 && nx - (-nvx)*((-nvx)-1)/2 < 0) continue;
            if (nvy>0 && ny + nvy*(nvy-1)/2 > Y) continue;
            if (nvy<0 && ny - (-nvy)*((-nvy)-1)/2 < 0) continue;
            
            if (dist_arr[nx][ny][nvx+VOFF][nvy+VOFF] != -1) continue;
            if (segment_blocked(s.x,s.y,nx,ny)) continue;
            
            dist_arr[nx][ny][nvx+VOFF][nvy+VOFF] = (short)(d+1);
            enqueue(nx,ny,nvx,nvy);
        }
    }
    printf("-1\n");
    free(queue);
    return 0;
}