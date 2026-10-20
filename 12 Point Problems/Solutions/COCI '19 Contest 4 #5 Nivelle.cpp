#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;static char b[100005];scanf("%d %s",&n,b);
    long long bn=1,bd=0;int bl=0,br=0;
    for(int k=1;k<=26;k++){
        int c[26]={},d=0,l=0;
        for(int r=0;r<n;r++){
            if(!c[b[r]-'a']++)d++;
            while(d>k)if(!--c[b[l++]-'a'])d--;
            long long len=r-l+1;
            if((long long)d*bd<bn*len||bd==0){bn=d;bd=len;bl=l;br=r;}
        }
    }
    printf("%d %d\n",bl+1,br+1);
}