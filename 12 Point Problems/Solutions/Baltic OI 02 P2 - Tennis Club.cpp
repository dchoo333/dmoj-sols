#include <bits/stdc++.h>
using namespace std;

const int M=1000;

struct P{int a,b;};

int n;
P p[M];
bool g[M][M];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].b;
        p[i].a=i;
    }

    for(int i=0;i<n;i++){
        int k=i;
        for(int j=i+1;j<n;j++)
            if(p[j].b>p[k].b) k=j;
        if(k!=i) swap(p[i],p[k]);
    }

    bool ok=1;

    for(int k=0;k<n && p[k].b>0;k++){
        int i=k+1;
        while(p[k].b>0 && i<n && p[i].b>0){
            g[p[k].a][p[i].a]=g[p[i].a][p[k].a]=1;
            p[k].b--;
            p[i].b--;
            i++;
        }
        if(p[k].b>0){
            ok=0;
            break;
        }
        int j=i-1;
        while(i<n && p[j].b<p[i].b) i++;
        i--;
        while(j>k && p[j].b<p[i].b){
            swap(p[j],p[i]);
            j--;
            i--;
        }
    }

    if(ok){
        cout<<"SCHEDULE\n";
        for(int i=0;i<n;i++){
            bool f=0;
            for(int j=0;j<n;j++) if(g[i][j]){
                if(f) cout<<' ';
                cout<<j+1;
                f=1;
            }
            cout<<"\n";
        }
    }else{
        cout<<"NO SCHEDULE\n";
    }

    return 0;
}