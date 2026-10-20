#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c;scanf("%d %d",&r,&c);
    vector<string>g(r);
    for(auto&s:g){char b[405];scanf("%s",b);s=b;}
    int a=0;
    vector<char>f(c);
    for(int i=0;i<r;i++){
        fill(f.begin(),f.end(),1);
        for(int j=i;j<r;j++){
            int k=0,m=0;
            for(int x=0;x<c;x++){
                f[x]&=g[j][x]=='.';
                k=f[x]?k+1:0;
                m=max(m,k);
            }
            if(m)a=max(a,2*(j-i+1+m));
        }
    }
    printf("%d\n",a-1);
}