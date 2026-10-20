#include<bits/stdc++.h>
using namespace std;
struct D{string n;bool f;int p;map<string,int>c;};
vector<D>t;
int add(int p,string n,bool f){t.push_back({n,f,p,{}});int i=t.size()-1;if(p>=0)t[p].c[n]=i;return i;}
void rec(int u,vector<string>&o){for(auto&[k,v]:t[u].c){o.push_back(k);rec(v,o);}}
bool mt(const string&s,const string&q){
    bool a=0,b=0;
    vector<pair<char,bool>>p;
    int i=0,m=q.size();
    if(m&&q[0]=='^'){a=1;i=1;}
    for(;i<m;i++){
        if(q[i]=='\\'&&i+1<m){p.push_back({q[++i],0});}
        else if(q[i]=='$'&&i==m-1)b=1;
        else if(q[i]=='.')p.push_back({0,1});
        else p.push_back({q[i],0});
    }
    int l=p.size(),n=s.size();
    for(int st=0;st+l<=n;st++){
        if(a&&st)break;
        if(b&&st+l!=n)continue;
        bool k=1;
        for(int j=0;j<l&&k;j++)if(!p[j].second&&p[j].first!=s[st+j])k=0;
        if(k)return 1;
    }
    return 0;
}
void out(vector<string>v){
    sort(v.begin(),v.end());
    string r;
    for(int i=0;i<(int)v.size();i++){if(i)r+='\n';r+=v[i];}
    cout<<r<<"\n\n";
}
int main(){
    int n;
    string ln;
    getline(cin,ln);
    n=stoi(ln);
    add(-1,"~",0);
    vector<int>st={0};
    for(int i=0;i<n;i++){
        getline(cin,ln);
        stringstream ss(ln);
        int d;string s;ss>>d>>s;
        st.resize(d+1);
        st.push_back(add(st[d],s,s.find('.')!=string::npos));
    }
    int c=0;
    while(getline(cin,ln)){
        stringstream ss(ln);
        vector<string>w;string x;
        while(ss>>x)w.push_back(x);
        if(w.empty())continue;
        if(w[0]=="exit")break;
        if(w[0]=="ls"){
            vector<string>v;
            bool r=w.size()>1&&w[1]=="-r";
            if(r)rec(c,v);
            else for(auto&[k,_]:t[c].c)v.push_back(k);
            auto it=find(w.begin(),w.end(),"grep");
            if(it!=w.end()&&it+1!=w.end()){
                string q=*(it+1);
                vector<string>u;
                for(auto&s:v)if(mt(s,q))u.push_back(s);
                v=u;
            }
            out(v);
        }else if(w[0]=="cd"&&w.size()>1){
            string p=w[1];
            int u=c;
            if(p=="~"||p.rfind("~/",0)==0){u=0;p=p.size()>1?p.substr(2):"";}
            stringstream ps(p);
            string s;bool ok=1;
            while(ok&&getline(ps,s,'/')){
                if(s.empty()||s==".")continue;
                if(s==".."){if(t[u].p>=0)u=t[u].p;continue;}
                auto f=t[u].c.find(s);
                if(f==t[u].c.end()||t[f->second].f)ok=0;
                else u=f->second;
            }
            if(ok)c=u;
        }else if(w[0]=="mkdir"&&w.size()>1){
            if(!t[c].c.count(w[1]))add(c,w[1],0);
        }else if(w[0]=="touch"&&w.size()>1){
            if(!t[c].c.count(w[1]))add(c,w[1],1);
        }else if(w[0]=="pwd"){
            string r;
            for(int u=c;u>0;u=t[u].p)r=t[u].n+"/"+r;
            out({"~/"+r});
        }
    }
}