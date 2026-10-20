#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c!=-1&&(c<'0'||c>'9'))c=gc();int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
int n;
static char a[1000001],b[1000001];
int f(char*m){
    int s=-1,l=-1,g=0;
    for(int i=0;i<n;i++)if(m[i]){if(s<0)s=i;else g=max(g,i-l);l=i;}
    g=max(g,s+n-l);
    return (n-g+1)/2;
}
int main(){
    n=rd();
    for(int i=0;i<n;i++){
        int c=rd()-1;
        a[((c-i)%n+n)%n]=1;
        b[((c-(n-1-i))%n+n)%n]=1;
    }
    printf("%d\n",min(f(a),f(b)));
}