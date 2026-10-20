#include<bits/stdc++.h>
using namespace std;
int h[1005];
int main(){
    int n;scanf("%d",&n);
    int a=INT_MAX,b=0,m=0;
    for(int i=0;i<n;i++){
        int l,r,y;scanf("%d %d %d",&l,&r,&y);
        for(int c=l;c<r;c++)h[c]=max(h[c],y);
        a=min(a,l);b=max(b,r);m=max(m,y);
    }
    long long p=0;
    for(int c=a;c<=b;c++){
        p+=abs(h[c]-h[c-1]);
        if(c<b&&h[c])p++;
    }
    printf("%lld\n",p);
    auto in=[&](int c,int y){return y<=0||(c>=a&&c<b&&y<=h[c]);};
    string o;
    for(int y=m;y>=1;y--){
        for(int c=a;c<b;c++){
            if(!in(c,y)){o+='.';continue;}
            bool e=0;
            for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++)if(!in(c+dx,y+dy))e=1;
            o+=e?'#':'.';
        }
        o+='\n';
    }
    o+=string(b-a,'*');
    o+='\n';
    fputs(o.c_str(),stdout);
}