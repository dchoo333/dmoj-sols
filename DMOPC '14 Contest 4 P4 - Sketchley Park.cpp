#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    static char s[100005],k[30];scanf("%s",s);int m=strlen(s);
    const char*h="HAILHYDRA";
    unordered_set<ll>st;
    for(int p=0;p+9<=m;p++){
        bool ok=1;
        for(int i=0;i<9&&ok;i++)for(int j=i+1;j<9&&ok;j++)if((h[i]==h[j])!=(s[p+i]==s[p+j]))ok=0;
        if(!ok)continue;
        ll g=0;for(int i:{0,1,2,3,5,6,7})g=g*26+s[p+i]-'A';
        st.insert(g);
    }
    int n;scanf("%d",&n);
    while(n--){
        scanf("%s",k);
        ll g=0;for(int i:{0,1,2,3,5,6,7})g=g*26+k[h[i]-'A']-'A';
        if(st.count(g)){
            char inv[26];for(int i=0;i<26;i++)inv[k[i]-'A']='A'+i;
            for(int i=0;i<m;i++)s[i]=inv[s[i]-'A'];
            puts(s);return 0;
        }
    }
    puts("KeyNotFoundError");
}