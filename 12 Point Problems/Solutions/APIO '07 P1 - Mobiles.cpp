#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];

    vector<int> lo(n+1), hi(n+1);
    long long swaps=0;
    for(int i=n;i>=1;i--){
        int aLo = (a[i]==-1)?1:lo[a[i]]+1;
        int aHi = (a[i]==-1)?1:hi[a[i]]+1;
        int bLo = (b[i]==-1)?1:lo[b[i]]+1;
        int bHi = (b[i]==-1)?1:hi[b[i]]+1;
        if(aLo>=bHi){ }
        else if(bLo>=aHi){ swaps++; }
        else { cout<<-1<<"\n"; return 0; }
        lo[i]=min(aLo,bLo); hi[i]=max(aHi,bHi);
        if(hi[i]-lo[i]>1){ cout<<-1<<"\n"; return 0; }
    }
    cout<<swaps<<"\n";
    return 0;
}