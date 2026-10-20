#include <bits/stdc++.h>
using namespace std;
int n,m,z;
vector<int>t;vector<long long>s;
int main(){
    scanf("%d %d",&n,&m);
    z=1<<n;t.assign(2*z,0);s.assign(z+1,0);
    for(int i=1;i<=z;i++){scanf("%lld",&s[i]);t[z+i-1]=i;}
    for(int v=z-1;v>=1;v--)t[v]=s[t[2*v]]>s[t[2*v+1]]?t[2*v]:t[2*v+1];
    string o;
    char c[3];
    while(m--){
        scanf("%s",c);
        if(c[0]=='R'){
            int i;long long x;scanf("%d %lld",&i,&x);
            s[i]=x;
            for(int v=(z+i-1)>>1;v;v>>=1)t[v]=s[t[2*v]]>s[t[2*v+1]]?t[2*v]:t[2*v+1];
        }else if(c[0]=='W'){
            o+=to_string(t[1]);o+='\n';
        }else{
            int i;scanf("%d",&i);
            int r=0;
            for(int v=(z+i-1)>>1;v&&t[v]==i;v>>=1)r++;
            o+=to_string(r);o+='\n';
        }
    }
    fputs(o.c_str(),stdout);
}