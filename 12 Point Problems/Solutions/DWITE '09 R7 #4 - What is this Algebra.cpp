#include<bits/stdc++.h>
using namespace std;

vector<string> tk;
int pos;

string tok(){return tk[pos++];}
string pk(){if(pos<tk.size())return tk[pos];return "";}

vector<string> tz(string s){
    string r="";
    for(char c:s)if(c!=' ')r+=c;
    vector<string> v;
    int i=0;
    while(i<r.size()){
        if(string("()^*/+-").find(r[i])!=string::npos){
            v.push_back(string(1,r[i]));i++;
        } else if(isdigit(r[i])){
            int j=i;
            while(j<r.size()&&isdigit(r[j]))j++;
            v.push_back(r.substr(i,j-i));i=j;
        } else i++;
    }
    return v;
}

long long pa();
long long pe();
long long pm();
long long pl();

long long pa(){
    long long l=pm();
    while(pk()=="+"||pk()=="-"){
        string op=tok();
        long long r=pm();
        l=op=="+"?l+r:l-r;
    }
    return l;
}

long long pm(){
    long long l=pe();
    while(pk()=="*"||pk()=="/"){
        string op=tok();
        long long r=pe();
        l=op=="*"?l*r:(long long)(l/(double)r);
    }
    return l;
}

long long pe(){
    long long l=pl();
    while(pk()=="^"){
        tok();
        long long r=pl();
        string a=to_string(abs(l)),b=to_string(abs(r));
        l=stoll(a+b);
    }
    return l;
}

long long pl(){
    if(pk()=="-"){tok();return -pl();}
    if(pk()=="+"){tok();return pl();}
    if(pk()=="("){
        tok();
        long long v=pa();
        tok();
        return v;
    }
    return stoll(tok());
}

int main(){
    for(int i=0;i<5;i++){
        string line;
        getline(cin,line);
        tk=tz(line);
        pos=0;
        cout<<pa()<<"\n";
    }
}