#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd(),m=rd();
    vector<int>h(n+1,-1),nx(m),to(m);
    for(int i=0;i<m;i++){int a=rd(),b=rd();to[i]=b;nx[i]=h[a];h[a]=i;}
    vector<int>id(n+1,-1),lo(n+1),cm(n+1,-1),it(n+1),stk,cs;
    vector<int>R;int t=0,k=0;
    for(int s=1;s<=n;s++){
        if(id[s]>=0)continue;
        cs.push_back(s);id[s]=lo[s]=t++;stk.push_back(s);it[s]=h[s];
        while(!cs.empty()){
            int u=cs.back();
            if(it[u]>=0){
                int e=it[u];it[u]=nx[e];int v=to[e];
                if(id[v]<0){id[v]=lo[v]=t++;stk.push_back(v);it[v]=h[v];cs.push_back(v);}
                else if(cm[v]<0)lo[u]=min(lo[u],id[v]);
            }else{
                cs.pop_back();
                if(!cs.empty())lo[cs.back()]=min(lo[cs.back()],lo[u]);
                if(lo[u]==id[u]){
                    int r=0;vector<int>mem;
                    while(1){int w=stk.back();stk.pop_back();cm[w]=k;mem.push_back(w);r=max(r,w);if(w==u)break;}
                    for(int w:mem)for(int e=h[w];e>=0;e=nx[e])if(cm[to[e]]!=k)r=max(r,R[cm[to[e]]]);
                    R.push_back(r);k++;
                }
            }
        }
    }
    for(int x=n;x>=1;x--)if(R[cm[x]]>x){printf("%d %d\n",x,R[cm[x]]);return 0;}
    puts("-1");
}