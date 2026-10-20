#include<bits/stdc++.h>
using namespace std;
struct F{double s,v;int t;};
int main(){
    int n;cin>>n;
    vector<double>r(n+1);
    for(int i=1;i<=n;i++)cin>>r[i];
    string s;cin>>s;
    vector<F>st;
    st.push_back({0,0,0});
    auto add=[&](double x){st.back().s+=x;st.back().v+=1/x;};
    for(size_t i=0;i<s.size();i++){
        char c=s[i];
        if(c=='(')st.push_back({0,0,0});
        else if(c=='R'){add(r[s[i+1]-'0']);i++;}
        else if(c=='-')st.back().t=1;
        else if(c=='|')st.back().t=2;
        else if(c==')'){
            F f=st.back();st.pop_back();
            add(f.t==2?1/f.v:f.s);
        }
    }
    printf("%.5f\n",st.back().s);
}