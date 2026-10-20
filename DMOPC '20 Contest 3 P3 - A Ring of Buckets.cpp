#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long m=1000000007;

    auto p=[&](long long b,long long e){
        long long r=1;
        b%=m;
        while(e){
            if(e&1) r=r*b%m;
            b=b*b%m;
            e>>=1;
        }
        return r;
    };

    auto iv=[&](long long a){
        long long b=a%m,r=1,e=m-2;
        while(e){
            if(e&1) r=r*b%m;
            b=b*b%m;
            e>>=1;
        }
        return r;
    };

    auto g=[&](long long b,long long n){
        b%=m;
        if(b<0) b+=m;
        if(b==1) return n%m;
        long long bn=p(b,n);
        return (bn-1+m)%m*iv((b-1+m)%m)%m;
    };

    int q;
    cin>>q;

    while(q--){
        long long n,M,k,B;
        cin>>n>>M>>k>>B;

        B%=m;
        if(B<0) B+=m;

        bool s=(k==2&&n%2==0)||(k==1&&n%3==0);

        if(!s){
            long long d=k+2;
            if(M%d){
                cout<<-1<<"\n";
                continue;
            }
            long long c=(M/d)%m;
            cout<<c*g(B,n)%m<<"\n";
            continue;
        }

        if(k==2){
            if(M%2){
                cout<<-1<<"\n";
                continue;
            }
            long long h=(M/2)%m;
            long long b2=B*B%m;
            long long t=g(b2,n/2);
            cout<<h*B%m*t%m<<"\n";
        }else{
            long long Mm=M%m;
            long long b2=B*B%m;
            long long b3=b2*B%m;
            long long t=g(b3,n/3);
            cout<<Mm*b2%m*t%m<<"\n";
        }
    }
}