#include <bits/stdc++.h>
using namespace std;

string sub(string a, string b) {
    int n = a.size(), m = b.size();
    string r = "";
    int carry = 0;
    for(int i=0;i<n;i++){
        int x = a[n-1-i]-'0';
        int y = (i<m ? b[m-1-i]-'0' : 0);
        int d = x - y - carry;
        if(d<0){d+=10; carry=1;} else carry=0;
        r += (d+'0');
    }
    while(r.size()>1 && r.back()=='0') r.pop_back();
    reverse(r.begin(), r.end());
    return r;
}

bool ge(string a, string b){
    if(a.size()!=b.size()) return a.size()>b.size();
    return a>=b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string n,d;
        cin>>n>>d;
        string q="",r="";
        for(char c:n){
            r += c;
            while(r.size()>1 && r[0]=='0') r.erase(0,1);
            int x=0;
            while(ge(r,d)){
                r=sub(r,d);
                x++;
            }
            q += (x+'0');
        }
        while(q.size()>1 && q[0]=='0') q.erase(0,1);
        if(r=="") r="0";
        cout<<q<<"\n"<<r<<"\n";
        if(t) cout<<"\n";
    }
}
