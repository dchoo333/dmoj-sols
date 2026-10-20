#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> rd(){
    int x,y,m;scanf("%d %d %d",&x,&y,&m);
    vector<pair<int,int>>p;
    for(int i=0;i<m;i++){
        int d;char c;scanf("%d %c",&d,&c);
        int s=d<0?-1:1;
        for(int k=0;k<abs(d);k++){
            p.push_back({x,y});
            if(c=='X')x+=s;else y+=s;
        }
    }
    if(p.empty())p.push_back({x,y});
    return p;
}
int main(){
    auto a=rd(),b=rd();
    long long p=a.size(),q=b.size(),l=p/__gcd(p,q)*q,r=LLONG_MAX;
    int i=0,j=0;
    for(long long t=0;t<l&&r;t++){
        long long dx=a[i].first-b[j].first,dy=a[i].second-b[j].second;
        r=min(r,dx*dx+dy*dy);
        if(++i==p)i=0;
        if(++j==q)j=0;
    }
    printf("%.2f\n",sqrt((double)r));
}