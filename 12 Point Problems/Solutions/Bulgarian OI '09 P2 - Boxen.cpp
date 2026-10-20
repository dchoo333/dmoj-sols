#include<bits/stdc++.h>
using namespace std;
int p[100005];
int f(int x){while(p[x]!=x)x=p[x]=p[p[x]];return x;}
int main(){
    for(int t=0;t<2;t++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)p[i]=i;
        int c=n;
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            int x=f(i),y=f(a);
            if(x!=y){p[x]=y;c--;}
        }
        printf("%d%c",c,t?'\n':' ');
    }
    return 0;
}
