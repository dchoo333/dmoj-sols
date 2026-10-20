#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int n;
vector<string>s;
vector<int>c;
long long F[3005],r=1;
void go(int l,int h,int d){
    int k=0,i=l;
    if((int)s[l].size()==d){k++;i++;}
    while(i<=h){
        int j=i,m=INT_MAX;
        while(j<h&&c[j]>d){m=min(m,c[j]);j++;}
        k++;
        if(j>i)go(i,j,m);
        i=j+1;
    }
    r=r*F[k]%P;
}
int main(){
    cin>>n;
    s.resize(n);
    for(auto&x:s)cin>>x;
    sort(s.begin(),s.end());
    c.resize(n);
    for(int i=0;i+1<n;i++){
        int t=0;
        while(t<(int)s[i].size()&&t<(int)s[i+1].size()&&s[i][t]==s[i+1][t])t++;
        c[i]=t;
    }
    F[0]=1;
    for(int i=1;i<3005;i++)F[i]=F[i-1]*i%P;
    go(0,n-1,0);
    printf("%lld\n",r);
}