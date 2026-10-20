#include<bits/stdc++.h>
using namespace std;
int n;vector<int>p;
vector<vector<int>>cyc(){
    vector<vector<int>>r;vector<char>v(n+1,0);
    for(int i=1;i<=n;i++)if(!v[i]&&p[i]!=i){
        vector<int>c;for(int j=i;!v[j];j=p[j]){v[j]=1;c.push_back(j);}
        r.push_back(c);
    }
    return r;
}
void ap(const vector<int>&o){
    vector<int>q=p;int k=o.size();
    for(int t=0;t<k;t++)q[o[(t+1)%k]]=p[o[t]];
    p=q;
}
int main(){
    scanf("%d",&n);p.assign(n+1,0);for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    vector<vector<int>>ops;
    auto c=cyc();
    if(c.size()>1){vector<int>o;for(auto&x:c)o.push_back(x[0]);ops.push_back(o);ap(o);c=cyc();}
    if(c.size()==1){ops.push_back(c[0]);ap(c[0]);}
    printf("%d\n",(int)ops.size());
    for(auto&o:ops){printf("%d",(int)o.size());for(int x:o)printf(" %d",x);puts("");}
}