#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;long long k;
    cin>>n>>k;
    string s;cin>>s;
    string L="([{",R=")]}";
    auto t=[&](char c){int x=L.find(c);return x==-1?(int)R.find(c):x;};
    vector<int>st;
    vector<pair<int,int>>a,b;
    for(int i=0;i<n;i++){
        if(L.find(s[i])!=string::npos)st.push_back(i);
        else{
            if(st.empty()){puts("impossible");return 0;}
            int j=st.back();st.pop_back();
            if(t(s[j])==t(s[i]))b.push_back({j,i});
            else a.push_back({j,i});
        }
    }
    if(!st.empty()){puts("impossible");return 0;}
    long long m=a.size(),p=b.size(),e=k-m;
    if(e<0){puts("impossible");return 0;}
    long long c=min(p,e/2),r=e-2*c;
    if(r>m){puts("impossible");return 0;}
    for(int i=0;i<c;i++){
        auto[j,q]=b[i];
        int x=(t(s[j])+1)%3;
        s[j]=L[x];s[q]=R[x];
    }
    for(int i=0;i<m;i++){
        auto[j,q]=a[i];
        if(i<r){
            int x=3-t(s[j])-t(s[q]);
            s[j]=L[x];s[q]=R[x];
        }else s[q]=R[t(s[j])];
    }
    cout<<s<<"\n";
}