#include<bits/stdc++.h>
using namespace std;
const int M=10000001;
static int sp[M];
int main(){
    vector<int>pr;
    for(int i=2;i<M;i++){
        if(!sp[i]){sp[i]=i;pr.push_back(i);}
        for(int p:pr){if(p>sp[i]||(long long)p*i>=M)break;sp[p*i]=p;}
    }
    int n;scanf("%d",&n);
    string o;
    while(n--){
        long long x,y;scanf("%lld %lld",&x,&y);
        long long g=__gcd(x,y),s=x+y,r=0;
        if(g&&__builtin_ctzll(g)==__builtin_ctzll(s)){
            g>>=__builtin_ctzll(g);r=1;
            while(g>1){int p=sp[g],c=0;while(g%p==0){g/=p;c++;}r*=c+1;}
        }
        o+=to_string(r);o+='\n';
    }
    fputs(o.c_str(),stdout);
}