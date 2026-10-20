#include<bits/stdc++.h>
using namespace std;
static char bf[1<<16];int bl,bp;
int gc(){if(bp==bl){bl=fread(bf,1,sizeof bf,stdin);bp=0;if(bl<=0)return -1;}return bf[bp++];}
bool rd(long long&x){int c=gc();while(c!=-1&&(c<'0'||c>'9'))c=gc();if(c==-1)return 0;x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return 1;}
int main(){
 long long n,r,s,a;
 vector<long long> v,mb;vector<int> id;
 while(rd(n)){rd(r);rd(s);
  long long g=s/r,b=0,sv=0,pr=0;
  v.clear();id.clear();mb.clear();
  for(int i=0;i<n;i++){rd(a);
   b+=r*a;if(a>pr)b+=s*(a-pr);pr=a;
   long long cu=-1;
   while(!v.empty()&&v.back()<=a){
    long long vv=v.back(),m=mb.back();int j=id.back();
    if(i-j>=2){long long gg=i-j-1;if(gg<=g){long long lv=min(vv,a)-cu;if(lv>0)sv+=lv*(s-r*gg);}}
    cu=max(cu,max(vv,m));v.pop_back();id.pop_back();mb.pop_back();}
   if(!v.empty()){int j=id.back();
    if(i-j>=2){long long gg=i-j-1;if(gg<=g){long long lv=min(v.back(),a)-cu;if(lv>0)sv+=lv*(s-r*gg);}}}
   v.push_back(a);id.push_back(i);mb.push_back(cu);}
  printf("%lld\n",b-sv);}
}