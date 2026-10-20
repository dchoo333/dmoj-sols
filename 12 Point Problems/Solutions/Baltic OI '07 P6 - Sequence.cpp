#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l[1000001], r[1000001], a[1000001];
ll ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pq.push({-a[i],i});
        l[i]=i-1;
        r[i]=i+1;
    }

    while(pq.size()>1){
        int pos=pq.top().second;
        pq.pop();

        if(!l[pos]){
            ans += a[r[pos]];
            l[r[pos]]=l[pos];
        } else if(r[pos]>n){
            ans += a[l[pos]];
            r[l[pos]]=r[pos];
        } else {
            ans += min(a[l[pos]], a[r[pos]]);
            l[r[pos]]=l[pos];
            r[l[pos]]=r[pos];
        }
    }

    cout << ans << "\n";
    return 0;
}