#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)for(int j=0,x;j<n;j++){cin>>x;if(x)a[i]|=1<<j;}
    const int M=1e9+7,F=(1<<n)-1;
    vector<int>d(1<<n);d[0]=1;
    for(int m=0;m<F;m++)if(d[m]){
        int c=a[__builtin_popcount(m)]&~m;
        while(c){int b=c&-c;c^=b;d[m|b]=(d[m|b]+d[m])%M;}
    }
    cout<<d[F];
}