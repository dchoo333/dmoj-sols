#include <bits/stdc++.h>
using namespace std;
int n,r[505],c[505];
string o;int k=0;
void go(int*p,char a,char b){
    vector<int>s(n);iota(s.begin(),s.end(),0);
    sort(s.begin(),s.end(),[&](int x,int y){return p[x]<p[y];});
    vector<int>t(n);
    for(int i=0;i<n;i++)t[s[i]]=i+1;
    for(int i=0;i<n;i++){int x=s[i];while(p[x]>t[x]){p[x]--;o+=to_string(x+1)+' '+a+'\n';k++;}}
    for(int i=n-1;i>=0;i--){int x=s[i];while(p[x]<t[x]){p[x]++;o+=to_string(x+1)+' '+b+'\n';k++;}}
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d %d",&r[i],&c[i]);
    go(r,'U','D');
    go(c,'L','R');
    printf("%d\n%s",k,o.c_str());
}