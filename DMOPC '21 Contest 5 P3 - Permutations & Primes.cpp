#include<bits/stdc++.h>
using namespace std;
const int N=100000;
bool sp[N+5],w[N+5];vector<int>L;vector<int>suf[N+5];
int main(){
    for(int i=2;i<=N;i++)sp[i]=1;
    for(int i=2;i*i<=N;i++)if(sp[i])for(int j=i*i;j<=N;j+=i)sp[j]=0;
    for(int i=1;i<=N;i++){for(int j:L)if(sp[i-j]){w[i]=1;break;}if(!w[i])L.push_back(i);}
    for(int n:L){
        if(n<3)continue;
        if(w[n-1]){suf[n]={n,n-1};continue;}
        for(int k=3;k<=min(n,9);k++){
            int b=n-k;vector<char>pre(k);
            for(int t=0;t<k;t++){int pos=b+1+t;pre[t]=0;
                for(int j:L){if(j>b)break;if(sp[pos-j]){pre[t]=1;break;}}}
            vector<int>h(k);iota(h.begin(),h.end(),b+1);bool ok=0;
            do{
                vector<int>o(k);iota(o.begin(),o.end(),0);
                sort(o.begin(),o.end(),[&](int x,int y){return h[x]<h[y];});
                vector<char>W(k);
                for(int x:o){W[x]=pre[x];for(int y=0;y<k&&!W[x];y++)if(h[y]<h[x]&&sp[abs(x-y)]&&!W[y])W[x]=1;}
                int top=max_element(h.begin(),h.end())-h.begin();
                if(W[top]){ok=1;break;}
            }while(next_permutation(h.begin(),h.end()));
            if(ok){suf[n]=h;break;}
        }
    }
    int T;scanf("%d",&T);string o;
    while(T--){int n;scanf("%d",&n);
        if(n<3){o+="-1\n";continue;}
        int k=w[n]?0:suf[n].size();
        for(int i=1;i<=n-k;i++){o+=to_string(i);o+=' ';}
        for(int x:(w[n]?vector<int>():suf[n])){o+=to_string(x);o+=' ';}
        o.back()='\n';
    }
    fwrite(o.data(),1,o.size(),stdout);
}