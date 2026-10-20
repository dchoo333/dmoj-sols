#include<bits/stdc++.h>
static char ib[1<<16];
int ip,il;
int gc(){if(ip==il){il=fread(ib,1,sizeof ib,stdin);ip=0;if(il<=0)return -1;}return ib[ip++];}
int rd(){int c=gc();while(c<'0')c=gc();int r=0;while(c>='0'){r=r*10+c-'0';c=gc();}return r;}
static char ob[1<<16];
int op;
void fl(){fwrite(ob,1,op,stdout);op=0;}
void pc(char c){if(op==sizeof ob)fl();ob[op++]=c;}
void pn(int v){
    if(v<0){pc('-');pc('1');return;}
    char t[12];int q=0;
    if(!v)t[q++]='0';
    while(v){t[q++]='0'+v%10;v/=10;}
    while(q)pc(t[--q]);
}
static int h[1000006],j[1000006],st[1000006];
int main(){
    int n=rd();
    for(int i=0;i<n;i++)h[i]=rd();
    for(int i=0;i<n;i++)j[i]=rd();
    int t=0;
    for(int i=n-1;i>=0;i--){
        while(t&&h[st[t-1]]<=h[i])t--;
        int k=t-j[i];
        j[i]=k>=0?h[st[k]]:-1;
        st[t++]=i;
    }
    for(int i=0;i<n;i++){pn(j[i]);pc(i+1<n?' ':'\n');}
    fl();
    return 0;
}