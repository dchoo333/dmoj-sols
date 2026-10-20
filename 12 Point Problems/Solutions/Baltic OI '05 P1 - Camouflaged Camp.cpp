#include <bits/stdc++.h>
using namespace std;

struct C { int r,c,l,w,a,d,p0,p1,p2,p3,o0,o1,o2,o3; };

int R,Cs,L,W,N;
vector<int> M;

void precalc(C &x,int CsS) {
    x.p0=(x.r-1)*CsS+(x.c-1);
    x.p1=x.p0+x.w;
    x.p2=x.p0+x.l*CsS;
    x.p3=x.p2+x.w;
    if(x.a==1) { // vertical
        x.o0=x.p2; x.o1=x.p3;
        x.o2=x.o0+x.l*CsS; x.o3=x.o2+x.w;
    } else { // horizontal
        x.o0=x.p1; x.o1=x.o0+x.w;
        x.o2=x.p3; x.o3=x.o2+x.w;
    }
}

void mss(vector<int> &map,int R,int C,vector<int> &sum) {
    sum.assign((R+1)*(C+1),0);
    for(int i=1;i<=R;i++){
        int row=0;
        for(int j=1;j<=C;j++){
            row+=map[(i-1)*C+(j-1)];
            sum[i*(C+1)+j]=row+sum[(i-1)*(C+1)+j];
        }
    }
}

void solve(vector<int> &map,vector<C> &ch,int &mx,int &br,int &bc) {
    vector<int> sM;
    mss(map,R,Cs,sM);
    for(int i=0;i<=R-L;i++){
        for(int j=0;j<=Cs-W;j++){
            int ok=0;
            int *o=sM.data()+i*(Cs+1)+j;
            for(int k=N-1;k>=0;k--){
                int sum1=o[ch[k].p0]-o[ch[k].p1]-o[ch[k].p2]+o[ch[k].p3];
                int sum2=o[ch[k].o0]-o[ch[k].o1]-o[ch[k].o2]+o[ch[k].o3];
                if(ch[k].d==0){
                    if(sum1<sum2) ok++;
                } else {
                    if(sum1>=sum2) ok++;
                }
                if(ok+k<=mx) break;
            }
            if(ok>mx){ mx=ok; br=i+1; bc=j+1; }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> R >> Cs;
    M.resize(R*Cs);
    for(int i=0;i<R*Cs;i++) cin >> M[i];
    cin >> L >> W >> N;
    vector<C> ch(N);
    for(int i=0;i<N;i++){
        cin >> ch[i].r >> ch[i].c >> ch[i].l >> ch[i].w >> ch[i].a >> ch[i].d;
        precalc(ch[i],Cs+1);
    }
    int mx=0,br=1,bc=1;
    solve(M,ch,mx,br,bc);
    cout << br << " " << bc << "\n";
}
