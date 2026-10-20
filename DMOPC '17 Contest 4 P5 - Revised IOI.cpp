#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char s[4][1000005];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<4;i++)scanf("%s",s[i]);
    vector<int>pt(n);ll k[16]={0};
    for(int j=0;j<n;j++){
        int p=0;for(int i=0;i<4;i++)if(s[i][j]=='T')p|=1<<i;
        pt[j]=p;k[(p&1)?p:15^p]++;
    }
    ll best=-1;int bm=0;
    for(int m=0;m<256;m++){
        ll sc[4]={0};
        for(int c=0;c<8;c++){
            int cl=c*2+1;ll sg=(m>>c&1)?1:-1;
            for(int i=0;i<4;i++)sc[i]+=sg*k[cl]*((cl>>i&1)?1:-1);
        }
        ll t=0;for(int i=0;i<4;i++)t+=sc[i]*sc[i];
        if(t>best){best=t;bm=m;}
    }
    string o(n,'T');
    for(int j=0;j<n;j++){
        int p=pt[j],c=(p&1)?p:15^p,pos=bm>>(c/2)&1;
        o[j]=((p==c)==(bool)pos)?'T':'F';
    }
    puts(o.c_str());
}