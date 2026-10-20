#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%d %d",&n,&k);
    vector<int>v(n),s(n);
    for(auto&x:v)scanf("%d",&x);
    s=v;
    sort(s.begin(),s.end());
    vector<int>t;
    for(int x:v){
        int c=(lower_bound(s.begin(),s.end(),x)-s.begin())/k;
        auto it=upper_bound(t.begin(),t.end(),c);
        if(it==t.end())t.push_back(c);
        else *it=c;
    }
    printf("%d\n",n-(int)t.size());
}