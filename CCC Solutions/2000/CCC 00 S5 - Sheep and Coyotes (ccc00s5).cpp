#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<long double,long double> s[1000];
    for (int i=0;i<n;i++){
        long double x,y;
        cin >> x >> y;
        s[i] = {x,y};
    }

    for (int i=0;i<n;i++){
        long double l=0,r=1000;
        for (int j=0;j<n;j++){
            if (i==j) continue;
            if (s[i].first==s[j].first){
                if (s[i].second<s[j].second) continue;
                else goto next;
            }
            long double midX=(s[i].first+s[j].first)/2, midY=(s[i].second+s[j].second)/2;
            long double split;
            if (s[i].second==s[j].second) split=midX;
            else split=-(midY - (-(s[i].first-s[j].first)/(s[i].second-s[j].second))*midX) / (-(s[i].first-s[j].first)/(s[i].second-s[j].second));
            if (s[i].first<s[j].first && r>split) r=split;
            if (s[i].first>s[j].first && split>l) l=split;
        }
        if (l<=r) printf("The sheep at (%.2Lf, %.2Lf) might be eaten.\n", s[i].first, s[i].second);
        next:;
    }
}


