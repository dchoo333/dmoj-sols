#include<bits/stdc++.h>
using namespace std;
static char bf[1<<16];int bl,bp;
int gc(){if(bp==bl){bl=fread(bf,1,sizeof bf,stdin);bp=0;if(bl<=0)return -1;}return bf[bp++];}
bool rd(int&x){int c=gc();while(c!=-1&&(c<'0'||c>'9'))c=gc();if(c==-1)return 0;x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return 1;}
int main(){
 int n,k;vector<int> f,g,c,st,sz;
 while(rd(n)){rd(k);
  if((int)c.size()<k+1){c.resize(k+1);st.resize(k+1);}
  fill(c.begin(),c.begin()+k+1,0);fill(st.begin(),st.begin()+k+1,-1);
  f.clear();g.assign(n+1,0);sz.assign(n,0);
  for(int i=0;i<n;i++){int m;rd(m);int t=0;
   for(int j=0;j<m;j++){int v;rd(v);if(st[v]!=i){st[v]=i;f.push_back(v);t++;}}
   sz[i]=m;g[i+1]=g[i]+t;}
  int h=0,l=0;long long s=0,b=-1;
  for(int x=0;x<2*n;x++){int i=x<n?x:x-n;
   for(int p=g[i];p<g[i+1];p++)if(!c[f[p]]++)h++;
   s+=sz[i];
   while(x-l+1>n){int j=l<n?l:l-n;for(int p=g[j];p<g[j+1];p++)if(!--c[f[p]])h--;s-=sz[j];l++;}
   while(h==k){if(b<0||s<b)b=s;int j=l<n?l:l-n;for(int p=g[j];p<g[j+1];p++)if(!--c[f[p]])h--;s-=sz[j];l++;}}
  printf("%lld\n",b);}
}