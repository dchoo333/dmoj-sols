#include <bits/stdc++.h>
using namespace std;

long long m=1e9+7,p=29;

int solve2(string s){
    int n=s.size(),r=0;
    long long h1=0,h2=0,pp=1;
    for(int i=0;i<n;i++){
        h1=(h1*p+s[i]-'a'+1)%m;
        h2=(h2+pp*(s[i]-'a'+1))%m;
        if(h1==h2) r=i;
        pp=(pp*p)%m;
    }
    return r+1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int z=0;z<10;z++){
        string s;
        cin>>s;
        int n=s.size();
        int a=solve2(s);
        reverse(s.begin(),s.end());
        int b=solve2(s);
        cout<<n-max(a,b)<<"\n";
    }
}