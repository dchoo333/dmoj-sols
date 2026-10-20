#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;double t,a,c,d,p,e;
    while(scanf("%d %lf %lf %lf %lf %lf %lf",&n,&t,&a,&c,&d,&p,&e)==7){
        vector<double>f(n+1,0),s(n+1,0),g(n+1,1e300);
        vector<int>b(n+1,-1);
        for(int k=1;k<=n;k++){f[k]=(f[k-1]+c)/(1-d);s[k]=s[k-1]+f[k];}
        g[0]=0;
        for(int j=1;j<=n;j++)for(int i=0;i<j;i++){
            int k=j-i;
            double v=g[i]+k*t+a*s[k]+(i?p+e*f[k]:0);
            if(v<g[j]-1e-9){g[j]=v;b[j]=i;}
        }
        vector<int>v;
        for(int j=n;j>0;j=b[j])v.push_back(b[j]);
        reverse(v.begin(),v.end());
        vector<int>q(v.begin()+1,v.end());
        printf("%d %.3f %.3f %.3f %.3f %.3f %.3f\n",n,t,a,c,d,p,e);
        int x=q.empty()?n:q[0];
        printf("%.3f %.3f %d\n",g[n],f[x],(int)q.size());
        for(int i=0;i<(int)q.size();i++){
            int y=i+1<(int)q.size()?q[i+1]:n;
            printf("%d %.3f\n",q[i],f[y-q[i]]);
        }
    }
}