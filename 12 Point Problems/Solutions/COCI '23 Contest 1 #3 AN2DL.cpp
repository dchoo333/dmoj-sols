#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c!='-'&&(c<'0'||c>'9'))c=gc();int s=1;if(c=='-'){s=-1;c=gc();}int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x*s;}
int main(){
    int n=rd(),m=rd();
    vector<short>a((size_t)n*m);
    for(auto&x:a)x=rd();
    int r=rd(),s=rd(),W=m-s+1,H=n-r+1;
    vector<short>t((size_t)n*W);
    vector<int>q(max(n,m));
    for(int i=0;i<n;i++){
        short*p=&a[(size_t)i*m];int h=0,e=0;
        for(int j=0;j<m;j++){
            while(e>h&&p[q[e-1]]<=p[j])e--;
            q[e++]=j;
            if(q[h]<=j-s)h++;
            if(j>=s-1)t[(size_t)i*W+j-s+1]=p[q[h]];
        }
    }
    vector<short>o((size_t)H*W);
    for(int j=0;j<W;j++){
        int h=0,e=0;
        for(int i=0;i<n;i++){
            short v=t[(size_t)i*W+j];
            while(e>h&&t[(size_t)q[e-1]*W+j]<=v)e--;
            q[e++]=i;
            if(q[h]<=i-r)h++;
            if(i>=r-1)o[(size_t)(i-r+1)*W+j]=t[(size_t)q[h]*W+j];
        }
    }
    string out;out.reserve((size_t)H*W*7);
    char b[8];
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        int x=o[(size_t)i*W+j];
        if(x<0){out+='-';x=-x;}
        int l=0;do{b[l++]='0'+x%10;x/=10;}while(x);
        while(l)out+=b[--l];
        out+=j+1<W?' ':'\n';
    }
    fwrite(out.data(),1,out.size(),stdout);
}