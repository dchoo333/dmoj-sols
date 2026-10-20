#include<bits/stdc++.h>
using namespace std;
struct S{int l,k,n[28];};
vector<S>a;
int ls;
int nw(int l,int k){S s;s.l=l;s.k=k;memset(s.n,-1,sizeof s.n);a.push_back(s);return a.size()-1;}
void ex(int c){
    int u=nw(a[ls].l+1,-1),p=ls;
    while(p!=-1&&a[p].n[c]==-1){a[p].n[c]=u;p=a[p].k;}
    if(p==-1)a[u].k=0;
    else{
        int q=a[p].n[c];
        if(a[p].l+1==a[q].l)a[u].k=q;
        else{
            int r=nw(a[p].l+1,a[q].k);
            memcpy(a[r].n,a[q].n,sizeof a[q].n);
            while(p!=-1&&a[p].n[c]==q){a[p].n[c]=r;p=a[p].k;}
            a[q].k=r;a[u].k=r;
        }
    }
    ls=u;
}
int ix(char c){if(c==' ')return 26;if(c>='a'&&c<='z')return c-'a';return 27;}
int main(){
    string t,p,s;
    getline(cin,t);
    while(getline(cin,s)){p+=s;p+='\n';}
    int m=p.size();
    string q(m,0);
    for(int i=0;i<m;i++){
        char c=p[i];
        if(c>='A'&&c<='Z')c=c-'A'+'a';
        q[i]=(c==' '||(c>='a'&&c<='z'))?c:1;
    }
    a.clear();nw(0,-1);ls=0;
    for(int i=0;i<m;i++)ex(q[i]==1?27:ix(q[i]));
    int n=t.size();
    vector<int>mx(n,0);
    for(int i=0;i<n;i++){
        int c=0,l=0;
        for(int j=i;j<n;j++){
            int e=ix(t[j]);
            if(e==27||a[c].n[e]==-1)break;
            c=a[c].n[e];l++;
        }
        mx[i]=l;
    }
    const int I=1e9;
    vector<int>d(n+1,I);
    d[0]=0;
    for(int i=0;i<n;i++){
        if(d[i]==I)continue;
        if(t[i]==' '&&d[i]<d[i+1])d[i+1]=d[i];
        for(int l=1;l<=mx[i];l++)if(d[i]+1<d[i+l])d[i+l]=d[i]+1;
    }
    vector<string>o;
    int i=0;
    while(i<n){
        if(t[i]==' '&&d[i+1]==d[i]){i++;continue;}
        int b=-1;
        for(int l=1;l<=mx[i];l++)if(d[i+l]==d[i]+1)b=l;
        string w=t.substr(i,b);
        size_t f=q.find(w);
        o.push_back(p.substr(f,b));
        i+=b;
    }
    printf("%d\n",(int)o.size());
    for(auto&w:o)printf("%s\n",w.c_str());
    return 0;
}