#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int>a(n),f(n+1,n),l(n+1,-1);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);f[a[i]]=min(f[a[i]],i);l[a[i]]=i;}
    vector<int>d(n,0),e(n);
    for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            int gl=f[a[i]]>=i&&l[a[i]]<=j,gr=f[a[j]]>=i&&l[a[j]]<=j;
            if(len==1)e[i]=gl;
            else e[i]=max(gl-d[i+1],gr-d[i]);
        }
        swap(d,e);
    }
    int D=0;for(int c=1;c<=n;c++)D+=l[c]>=0;
    printf("%d:%d\n",(D+d[0])/2,(D-d[0])/2);
}