#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin>>q;

    while(q--){
        int t;
        long long n,x;
        cin>>t>>n>>x;

        if(n==1){
            cout<<0<<"\n";
            continue;
        }

        if(t==1){
            long long f=x;
            if(f==0){
                cout<<-1<<"\n";
                continue;
            }

            long long l=0,h=n;

            while(l<h){
                long long m=(l+h)/2;
                long long b=m+1,e=f,tar=n,r=1,bb=b,ee=e;
                bool ok=false;

                if(bb==1) ok=(tar<=1);
                else{
                    while(ee>0){
                        if(ee&1){
                            if(r>tar/bb+1){ ok=true; break; }
                            r*=bb;
                            if(r>=tar){ ok=true; break; }
                        }
                        ee>>=1;
                        if(ee>0){
                            if(bb>tar/bb+1){ ok=true; break; }
                            bb*=bb;
                            if(bb>=tar){ ok=true; break; }
                        }
                    }
                    if(r>=tar) ok=true;
                }

                if(ok) h=m;
                else l=m+1;
            }

            cout<<l<<"\n";
        }else{
            long long d=x;
            long long b=d+1;

            if(b==1){
                cout<<-1<<"\n";
                continue;
            }

            long long l=0,h=n;

            while(l<h){
                long long m=(l+h)/2;
                long long bb=b,ee=m,tar=n,r=1;
                bool ok=false;

                if(bb==1) ok=(tar<=1);
                else{
                    while(ee>0){
                        if(ee&1){
                            if(r>tar/bb+1){ ok=true; break; }
                            r*=bb;
                            if(r>=tar){ ok=true; break; }
                        }
                        ee>>=1;
                        if(ee>0){
                            if(bb>tar/bb+1){ ok=true; break; }
                            bb*=bb;
                            if(bb>=tar){ ok=true; break; }
                        }
                    }
                    if(r>=tar) ok=true;
                }

                if(ok) h=m;
                else l=m+1;
            }

            cout<<l<<"\n";
        }
    }
}