#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void ad(map<string,ll>&m,vector<string>&v){
    for(string&s:v)for(int i=0;i+3<=(int)s.size();i++)m[s.substr(i,3)]++;
}
vector<string> rdm(){
    vector<string>v;
    string s;
    while(getline(cin,s)){
        while(s.size()&&s.back()=='\r')s.pop_back();
        if(s=="ENDMESSAGE")break;
        v.push_back(s);
    }
    return v;
}
double sim(map<string,ll>&a,map<string,ll>&b){
    double d=0,p=0,q=0;
    for(auto&e:a){
        p+=(double)e.second*e.second;
        auto it=b.find(e.first);
        if(it!=b.end())d+=(double)e.second*it->second;
    }
    for(auto&e:b)q+=(double)e.second*e.second;
    if(p==0||q==0)return 0;
    return d/(sqrt(p)*sqrt(q));
}
int main(){
    int s,n,k;
    string l;
    getline(cin,l);
    sscanf(l.c_str(),"%d %d %d",&s,&n,&k);
    map<string,ll>A,B;
    for(int i=0;i<s;i++){auto v=rdm();ad(A,v);}
    for(int i=0;i<n;i++){auto v=rdm();ad(B,v);}
    for(int i=0;i<k;i++){
        auto v=rdm();
        map<string,ll>M;
        ad(M,v);
        double x=sim(M,A),y=sim(M,B);
        printf("%.5f %.5f\n%s\n",x,y,x>y?"spam":"non-spam");
    }
    return 0;
}
