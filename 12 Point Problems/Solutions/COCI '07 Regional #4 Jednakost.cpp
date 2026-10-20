#include<bits/stdc++.h>
using namespace std;
static short f[1002][5001];static signed char ch[1002][5001];
int main(){
    static char b[2100];scanf("%s",b);
    string t=b;int e=t.find('=');string a=t.substr(0,e);int S=stoi(t.substr(e+1)),n=a.size();
    const short I=30000;
    for(int s=0;s<=S;s++)f[n][s]=s?I:0;
    for(int i=n-1;i>=0;i--)for(int s=0;s<=S;s++){
        short r=I;signed char c=-1;
        if(a[i]=='0'&&i<n-1){r=f[i+1][s];c=0;}
        else{
            int v=0;
            for(int j=i;j<n;j++){
                v=v*10+a[j]-'0';if(v>s)break;
                if(f[j+1][s-v]<I&&f[j+1][s-v]+1<r){r=f[j+1][s-v]+1;c=j-i+1;}
            }
        }
        f[i][s]=r;ch[i][s]=c;
    }
    string o;int i=0,s=S;bool st=1;
    while(i<n){
        int c=ch[i][s];
        if(!st)o+='+';
        st=c==0;
        if(c==0){o+='0';i++;continue;}
        int v=0;for(int j=i;j<i+c;j++){o+=a[j];v=v*10+a[j]-'0';}
        i+=c;s-=v;
    }
    printf("%s=%d\n",o.c_str(),S);
}