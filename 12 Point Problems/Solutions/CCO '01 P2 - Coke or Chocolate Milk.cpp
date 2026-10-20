#include <bits/stdc++.h>
using namespace std;

static inline int NEG(int l){ return l^1; }

int P;
vector<vector<int>> adj;
vector<int> val;

void aiki(int a,int b){ adj[a].push_back(b); }
void acl(int l1,int l2){ aiki(NEG(l1),l2); aiki(NEG(l2),l1); }
void auu(int l){ aiki(NEG(l),l); }

bool tyl(int lit, vector<int>& touched){
    size_t mark = touched.size();
    vector<int> st{lit};
    while(!st.empty()){
        int l = st.back(); st.pop_back();
        int v = l>>1, want = (l&1)?0:1;
        if(val[v]!=-1){
            if(val[v]!=want){
                for(size_t i=touched.size(); i>mark; --i) val[touched[i-1]]=-1;
                touched.resize(mark);
                return false;
            }
            continue;
        }
        val[v]=want; touched.push_back(v);
        for(int u: adj[l]) st.push_back(u);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while((cin>>n) && n){
        string dummy; getline(cin,dummy);
        vector<vector<string>> reqs(n);
        map<string,int> id;
        for(int i=0;i<n;i++){
            string line; getline(cin,line);
            istringstream ss(line);
            string tok;
            while(ss>>tok) reqs[i].push_back(tok);
        }
        for(auto&t:reqs){
            id[t[0]];
            for(size_t k=0;k+1<t.size();k++)
                if(t[k]=="as"||t[k]=="from"||t[k]=="if") id[t[k+1]];
        }
        P=0; for(auto&kv:id) kv.second=P++;
        adj.assign(2*P,{});
        val.assign(P,-1);

        auto readDrink=[&](vector<string>&t,size_t k,size_t&next){
            if(t[k]=="Coke"){ next=k+1; return 1; }
            next=k+2; return 0;
        };
        for(auto&t:reqs){
            int a=id[t[0]];
            size_t nx;
            if(t[1]=="hates"){
                int d=readDrink(t,2,nx);
                auu(2*a + (d?1:0));
            } else if(t[2]=="same"){
                int b=id[t[4]];
                acl(NEG(2*a),2*b); acl(2*a,NEG(2*b));
            } else if(t[2]=="different"){
                int b=id[t[4]];
                acl(2*a,2*b); acl(NEG(2*a),NEG(2*b));
            } else {
                int d1=readDrink(t,2,nx);
                if(nx<t.size() && t[nx]=="if"){
                    int b=id[t[nx+1]];
                    size_t nx2;
                    int d2=readDrink(t,nx+3,nx2);
                    acl(NEG(2*b + (d2?0:1)), 2*a + (d1?0:1));
                } else {
                    auu(2*a + (d1?0:1));
                }
            }
        }

        vector<int> touched;
        bool ok=true;
        for(int v=0; v<P && ok; v++){
            if(val[v]!=-1) continue;
            if(!tyl(2*v,touched))
                ok = tyl(2*v+1,touched);
        }

        if(!ok) cout<<"Everybody gets water\n";
        else for(auto&kv:id)
            cout<<kv.first<<" gets "<<(val[kv.second]?"Coke":"chocolate milk")<<"\n";
        cout<<"\n";
    }
    return 0;
}