#include <cstdio>
#include <string>
using namespace std;

const int MX=1000000;
int n, A[MX], B[MX], R[MX+1], L;
char a_[MX], b_[MX];
string a,b,f,t;
bool neg;

void eq(){
    int la=a.length(), lb=b.length();
    const char* ca=a.c_str();
    const char* cb=b.c_str();

    if(la>lb){
        int d=la-lb;
        for(int i=0;i<la;i++){
            A[i]=ca[i]-'0';
            B[i]=i>=d?cb[i-d]-'0':0;
        }
        L=la;
    }else if(lb>la){
        int d=lb-la;
        for(int i=0;i<lb;i++){
            B[i]=cb[i]-'0';
            A[i]=i>=d?ca[i-d]-'0':0;
        }
        L=lb;
    }else{
        for(int i=0;i<la;i++){
            A[i]=ca[i]-'0';
            B[i]=cb[i]-'0';
        }
        L=la;
    }
}

void add(){
    R[0]=0;
    for(int i=0;i<L;i++) R[i+1]=A[i]+B[i];
    for(int i=L;i>0;i--) if(R[i]>=10){R[i]-=10; R[i-1]++;}
    bool b=false;
    for(int i=0;i<=L;i++){
        if(!b&&R[i]!=0) b=true;
        if(b) f+=to_string(R[i]);
    }
}

void sub(){
    R[0]=0;
    for(int i=0;i<L;i++) R[i+1]=A[i]-B[i];
    int start=-1;
    for(int i=0;i<=L;i++) if(R[i]!=0){start=i; break;}
    neg=R[start]>=0;
    if(!neg) for(int i=L;i>=0;i--) R[i]=-R[i];
    for(int i=L;i>0;i--) if(R[i]<0){R[i]+=10; R[i-1]--;}
    bool b=false;
    for(int i=0;i<=L;i++){
        if(!b&&R[i]!=0) b=true;
        if(b) f+=to_string(R[i]);
    }
}

string sgn(string x){return x.substr(1);}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s",a_,b_);
        a=string(a_); b=string(b_);
        bool sa=a[0]=='-', sb=b[0]=='-';

        if(sa){
            if(sb){
                a=sgn(a); b=sgn(b);
                eq(); add();
                printf("-%s\n", f.c_str());
            }else{
                a=sgn(a); t=a; a=b; b=t;
                eq(); sub();
                printf("%s%s\n", neg?"":"-", f.c_str());
            }
        }else{
            if(sb){
                b=sgn(b);
                eq(); sub();
                printf("%s%s\n", neg?"":"-", f.c_str());
            }else{
                eq(); add();
                printf("%s\n", f.c_str());
            }
        }
        if(f=="") printf("0\n");
        f="";
    }
}