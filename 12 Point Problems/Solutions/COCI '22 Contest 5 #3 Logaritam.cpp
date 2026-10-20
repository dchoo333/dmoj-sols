#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;scanf("%d %d",&n,&q);
    vector<int>pr;
    for(int i=2;i<=10000;i++){bool f=1;for(int p:pr){if(p*p>i)break;if(i%p==0){f=0;break;}}if(f)pr.push_back(i);}
    while(q--){
        int x;scanf("%d",&x);
        if(x==1){puts("-1");continue;}
        int b=1;
        for(int p:pr){if((long long)p*p>x)break;if(x%p==0){b=p;while(x%p==0)x/=p;}}
        if(x>1)b=max(b,x);
        printf("%d\n",n/b-1);
    }
}