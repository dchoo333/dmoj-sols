#include <bits/stdc++.h>
using namespace std;
vector<string>g;int s;
void p(int r,int c,char ch){c+=s;while((int)g.size()<=r)g.push_back("");if((int)g[r].size()<=c)g[r].resize(c+1,' ');g[r][c]=ch;}
void ps(int r,int c,const string&t){for(int i=0;i<(int)t.size();i++)if(t[i]!=' ')p(r,c+i,t[i]);}
int main(){
    int n;bool f=1;
    while(scanf("%d",&n)==1){
        int w=9,mh=0;
        for(int k=1;k<=n;k++){int h=k+2;mh=max(mh,(w+2*(h-1)-1)/2);w=w+2*(h-1)-2;}
        s=max(0,mh-10);g.clear();
        const char*hd[]={"          |","       \\  |  /","        \\ | /","         \\|/","       XXXXXXX","      X       X","     X  O   O  X","    X     V     X","W   X  X     X  X"," \\   X  XXXXX  X","  \\   X       X","   \\   XXXXXXX"};
        for(int i=0;i<12;i++)ps(i,0,hd[i]);
        p(12,4,'\\');ps(12,15,"---");p(13,18,'\\');p(14,19,'\\');p(15,20,'\\');p(16,21,'M');
        int r=12;w=9;
        for(int k=1;k<=n;k++){
            int h=k+2;
            for(int i=0;i<h;i++){
                int x=(w+2*i-1)/2;
                p(r,10-x,'X');p(r,10+x,'X');
                if(i>=1&&i<=k)p(r,10,'O');
                r++;
            }
            int b=w+2*(h-1)-2,x=(b-1)/2;
            for(int j=10-x;j<=10+x;j++)p(r,j,'X');
            r++;w=b;
        }
        ps(r,6,"OOOO OOOO");ps(r+1,6,"OOOO OOOO");
        if(!f)puts("");
        f=0;
        for(auto&l:g){while(!l.empty()&&l.back()==' ')l.pop_back();puts(l.c_str());}
    }
}