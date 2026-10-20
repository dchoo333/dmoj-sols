#include<bits/stdc++.h>
using namespace std;
int main(){
    static char b[100005];scanf("%s",b);string s=b;int n=s.size();
    vector<int>z(n,0);int l=0,r=0,m=0;
    for(int i=1;i<n;i++){
        if(i<r)z[i]=min(r-i,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]>r){l=i;r=i+z[i];}
        m=max(m,z[i]);
    }
    string t=s;reverse(t.begin(),t.end());
    string u=s+"#"+t;int k=u.size();vector<int>p(k,0);
    for(int i=1;i<k;i++){int j=p[i-1];while(j&&u[i]!=u[j])j=p[j-1];if(u[i]==u[j])j++;p[i]=j;}
    int L=p[k-1];
    while(L>m)L=p[L-1];
    printf("%d\n",L);
}