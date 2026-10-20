#include <bits/stdc++.h>
using namespace std;
int rd(){char s[16];scanf("%s",s);return s[0]=='?'?-1:atoi(s);}
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int g=rd(),w=rd(),d=rd(),l=rd(),p=rd();
        bool f=0;
        for(int a=w<0?0:w;a<=(w<0?100:w)&&!f;a++)
        for(int b=d<0?0:d;b<=(d<0?100:d)&&!f;b++)
        for(int c=l<0?0:l;c<=(l<0?100:l)&&!f;c++){
            if(a+b+c>100)break;
            if(g>=0&&a+b+c!=g)continue;
            if(p>=0&&3*a+b!=p)continue;
            printf("%d %d %d %d %d\n",a+b+c,a,b,c,3*a+b);
            f=1;
        }
    }
}