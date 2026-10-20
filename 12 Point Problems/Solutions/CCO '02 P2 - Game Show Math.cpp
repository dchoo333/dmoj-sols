#include<bits/stdc++.h>
using namespace std;
const int L=32000,W=64001;
static char vis[101][W];
static char opr[101][W];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int k;
        scanf("%d",&k);
        vector<int>a(k);
        for(int i=0;i<k;i++)scanf("%d",&a[i]);
        int t;
        scanf("%d",&t);
        for(int i=0;i<=k;i++)memset(vis[i],0,W);
        vis[0][a[0]+L]=1;
        for(int i=0;i+1<k;i++){
            int b=a[i+1];
            for(int v=0;v<W;v++){
                if(!vis[i][v])continue;
                long long x=v-L;
                long long r[4]={x+b,x-b,x*b,0};
                bool ok[4]={1,1,1,0};
                if(b&&x%b==0){r[3]=x/b;ok[3]=1;}
                for(int o=0;o<4;o++){
                    if(!ok[o]||r[o]<-L||r[o]>L)continue;
                    int u=r[o]+L;
                    if(!vis[i+1][u]){vis[i+1][u]=1;opr[i+1][u]=o;}
                }
            }
        }
        if(t<-L||t>L||!vis[k-1][t+L]){puts("NO EXPRESSION");continue;}
        string s;
        int v=t+L;
        const char*c="+-*/";
        for(int i=k-1;i>0;i--){
            int o=opr[i][v];
            long long x=v-L,p=0;
            if(o==0)p=x-a[i];
            else if(o==1)p=x+a[i];
            else if(o==2)p=x/a[i];
            else p=x*a[i];
            s=string(1,c[o])+to_string(a[i])+s;
            v=p+L;
        }
        printf("%d%s=%d\n",a[0],s.c_str(),t);
    }
    return 0;
}