#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    string s;
    while(getline(cin,s)){
        while(s.size()&&(s.back()=='\r'||s.back()==' '))s.pop_back();
        if(s.empty())continue;
        n=stoi(s);
        if(!n)break;
        set<string>ig;
        for(int i=0;i<n;i++){getline(cin,s);while(s.size()&&(s.back()=='\r'||s.back()==' '))s.pop_back();ig.insert(s);}
        while(getline(cin,s)){
            while(s.size()&&(s.back()=='\r'))s.pop_back();
            if(s.substr(0,9)=="LAST CASE")break;
            stringstream ss(s);
            string ab,w;
            ss>>ab;
            vector<string>ws;
            while(ss>>w)if(!ig.count(w))ws.push_back(w);
            string a=ab;
            for(char&ch:a)ch=tolower(ch);
            int m=a.size();
            vector<ll>f(m+1,0);
            f[0]=1;
            for(string&q:ws){
                vector<ll>nf(m+1,0);
                int L=q.size();
                for(int i=0;i<m;i++){
                    if(!f[i])continue;
                    vector<ll>d(m+1,0);
                    d[i]=1;
                    for(int k=0;k<L;k++)
                        for(int j=m;j>i;j--)
                            if(a[j-1]==q[k])d[j]+=d[j-1];
                    for(int j=i+1;j<=m;j++)if(d[j])nf[j]+=f[i]*d[j];
                }
                f=nf;
            }
            if(f[m])printf("%s can be formed in %lld ways\n",ab.c_str(),f[m]);
            else printf("%s is not a valid abbreviation\n",ab.c_str());
        }
    }
    return 0;
}