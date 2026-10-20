#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int main(){
    int n,k;static char a[1005];scanf("%d %d %s",&n,&k,a);
    vector<array<int,2>>d(k+2,{0,0}),e;d[0][0]=1;
    for(int i=n-1;i>=0;i--){
        e.assign(k+2,{0,0});
        int x=a[i]-'0';
        for(int c=0;c<=k;c++)for(int r=0;r<2;r++)if(d[c][r])for(int y=0;y<2;y++){
            int s=x+y+r,bt=s&1,nc=c+bt;if(nc>k)continue;
            e[nc][s>>1]=(e[nc][s>>1]+d[c][r])%P;
        }
        d=e;
    }
    printf("%d\n",(int)((d[k][0]+(k?d[k-1][1]:0))%P));
}