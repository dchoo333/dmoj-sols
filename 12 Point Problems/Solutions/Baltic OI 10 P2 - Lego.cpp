#include <bits/stdc++.h>
using namespace std;

#define ML 6
#define MH 6
#define MN (ML-1)*(ML-1)

char v[MH][2][ML+1];
int sp[MH+1][10000],nb[MH+1];
long long cnt,np[MH+1][10000];
int H,ps[MN];
int mp[ML][ML];

void f(int h,int nr,int lx,int ly){
  int x,y,i,j,k,q,d;
  char c[MN];
  for(x=lx;x<ML-1;x++){
    for(y=(x==lx)?ly+1:0;y<ML-1;y++){
      if(mp[x][y]==-1&&mp[x][y+1]==-1){
        ps[nr]=x*(ML-1)+y;
        mp[x][y]=mp[x+1][y]=mp[x][y+1]=mp[x+1][y+1]=nr;
        f(h,nr+1,x,y);
        mp[x][y]=mp[x+1][y]=mp[x][y+1]=mp[x+1][y+1]=-1;
      }
    }
  }
  for(i=0;i<nr;i++)c[i]='-';
  for(i=0;i<2;i++){
    for(j=0;j<ML;j++){
      q=-1;
      for(k=0;k<ML;k++){
        if(i==0){x=j;y=k;}
        if(i==1){y=j;x=ML-1-k;}
        if(i==2){x=ML-1-j;y=ML-1-k;}
        if(i==3){y=ML-1-j;x=k;}
        if(mp[x][y]!=-1){q=mp[x][y];break;}
      }
      if(q==-1&&v[h][i][j]!='.')return;
      if(q!=-1){
        if(v[h][i][j]=='.')return;
        if(c[q]=='-')c[q]=v[h][i][j];
        if(c[q]!=v[h][i][j])return;
      }
    }
  }
  d=1;
  for(i=0;i<nr;i++)if(c[i]=='-')d*=3;
  np[h+1][nb[h+1]]=0;
  for(i=0;i<nb[h];i++){
    for(j=0;j<nr;j++)if(((sp[h][i]>>ps[j])&1)==0)break;
    if(j==nr){
      np[h+1][nb[h+1]]+=np[h][i]*d;
      cnt+=np[h][i]*d;
    }
  }
  if(np[h+1][nb[h+1]]>0){
    sp[h+1][nb[h+1]]=0;
    for(x=0;x<ML-1;x++)for(y=0;y<ML-1;y++){
      q=x*(ML-1)+y;
      if(mp[x][y]!=-1||mp[x][y+1]!=-1||mp[x+1][y]!=-1||mp[x+1][y+1]!=-1)
        sp[h+1][nb[h+1]]|=(1<<q);
    }
    nb[h+1]++;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j,h;
  cin>>H;
  for(i=0;i<2;i++)for(h=H-1;h>=0;h--)cin>>v[h][i];
  nb[0]=1;
  np[0][0]=1;
  sp[0][0]=~0;
  for(h=0;h<H;h++){
    cnt=0;
    for(i=0;i<ML;i++)for(j=0;j<ML;j++)mp[i][j]=-1;
    f(h,0,-1,-1);
  }
  cout<<cnt<<"\n";
  return 0;
}
