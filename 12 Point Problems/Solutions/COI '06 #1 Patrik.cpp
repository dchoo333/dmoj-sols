#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd();
    vector<pair<int,int>>s;s.reserve(n);
    long long r=0;
    while(n--){
        int h=rd(),c=1;
        while(!s.empty()&&s.back().first<h){r+=s.back().second;s.pop_back();}
        if(!s.empty()&&s.back().first==h){
            c+=s.back().second;r+=s.back().second;s.pop_back();
        }
        if(!s.empty())r++;
        s.push_back({h,c});
    }
    printf("%lld\n",r);
}