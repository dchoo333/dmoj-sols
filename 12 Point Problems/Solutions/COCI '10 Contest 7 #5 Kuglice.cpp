#include <bits/stdc++.h>
using namespace std;
int p[300005];bool cy[300005];
int f(int x){int r=x;while(p[r]!=r)r=p[r];while(p[x]!=r){int t=p[x];p[x]=r;x=t;}return r;}
void ad(int x,int y){int r=f(y);if(r==x)cy[x]=1;else p[x]=r;}
int main(){
    int n;scanf("%d",&n);
    vector<int>nx(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&nx[i]);
    int q;scanf("%d",&q);
    vector<int>t(q),x(q);
    vector<char>dl(n+1,0);
    for(int i=0;i<q;i++){scanf("%d %d",&t[i],&x[i]);if(t[i]==2)dl[x[i]]=1;}
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++)if(nx[i]&&!dl[i])ad(i,nx[i]);
    vector<int>an;
    for(int i=q-1;i>=0;i--){
        if(t[i]==2)ad(x[i],nx[x[i]]);
        else{int r=f(x[i]);an.push_back(cy[r]?-1:r);}
    }
    string o;
    for(int i=an.size()-1;i>=0;i--){o+=an[i]<0?"CIKLUS":to_string(an[i]);o+='\n';}
    fputs(o.c_str(),stdout);
}