#include<bits/stdc++.h>
using namespace std;
static char s[1000006];
int main(){
    int K;
    scanf("%d",&K);
    vector<double>z(K+2,0);
    for(int i=1;i<=K;i++){int v;scanf("%d",&v);z[i]=v;}
    scanf("%s",s);
    vector<double>c;
    vector<int>st;
    vector<char>op;
    double m[64];
    for(char*p=s;*p;p++){
        char e=*p;
        if(e=='('){st.push_back(c.size());op.push_back(0);}
        else if(e=='?')op.back()='?';
        else if(e=='+'||e=='*')op.back()=e;
        else{
            int b=st.back();st.pop_back();
            char o=op.back();op.pop_back();
            double v;
            if(o=='?')v=z[1];
            else{
                int k=c.size()-b;
                for(int j=0;j<k;j++)m[j]=c[b+j];
                sort(m,m+k);
                double S=z[k],t=0;
                for(int j=0;j<k;j++)t+=m[j];
                if(o=='+')v=t<S?t:S;
                else if(t<=S){v=1;for(int j=0;j<k;j++)v*=m[j];}
                else{
                    v=1;
                    double P=0;
                    for(int i=0;i<k;i++){
                        double q=(S-P)/(k-i);
                        if(q<=m[i]){v*=pow(q,k-i);break;}
                        v*=m[i];P+=m[i];
                    }
                }
            }
            c.resize(b);
            c.push_back(v);
        }
    }
    printf("%.9f\n",c[0]);
    return 0;
}