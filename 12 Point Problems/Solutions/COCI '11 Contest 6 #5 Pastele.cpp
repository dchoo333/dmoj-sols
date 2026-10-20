#include<bits/stdc++.h>
using namespace std;
static int P[257][257][257];
int n,k;
vector<array<int,3>>v;
int S(int a,int b,int c,int d){
    int x=a+d+1,y=b+d+1,z=c+d+1;
    return P[x][y][z]-P[a][y][z]-P[x][b][z]-P[x][y][c]+P[a][b][z]+P[a][y][c]+P[x][b][c]-P[a][b][c];
}
bool ok(int d,array<int,3>*o){
    for(int a=0;a+d<=255;a++)for(int b=0;b+d<=255;b++)for(int c=0;c+d<=255;c++)
        if(S(a,b,c,d)>=k){if(o)*o={a,b,c};return 1;}
    return 0;
}
int main(){
    scanf("%d %d",&n,&k);
    v.resize(n);
    for(auto&x:v){scanf("%d %d %d",&x[0],&x[1],&x[2]);P[x[0]+1][x[1]+1][x[2]+1]++;}
    for(int a=1;a<=256;a++)for(int b=1;b<=256;b++)for(int c=1;c<=256;c++)
        P[a][b][c]+=P[a-1][b][c]+P[a][b-1][c]+P[a][b][c-1]-P[a-1][b-1][c]-P[a-1][b][c-1]-P[a][b-1][c-1]+P[a-1][b-1][c-1];
    int l=0,h=255;
    while(l<h){int m=(l+h)/2;if(ok(m,0))h=m;else l=m+1;}
    array<int,3>o;
    ok(l,&o);
    printf("%d\n",l);
    int c=0;
    for(auto&x:v){
        if(c==k)break;
        bool f=1;
        for(int j=0;j<3;j++)if(x[j]<o[j]||x[j]>o[j]+l)f=0;
        if(f){printf("%d %d %d\n",x[0],x[1],x[2]);c++;}
    }
}