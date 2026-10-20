#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        long long X,R,C; scanf("%lld %lld %lld",&X,&R,&C);
        long long m=min(R,C), M=max(R,C);
        bool richard = (R*C % X != 0) || (X >= 7) || (X > M) || (X >= 3 && m == 1) || (X >= 4 && m == 2) || (X == 6 && m == 3) || (X == 5 && m == 3 && M == 5);
        printf("Case #%d: %s\n", tc, richard ? "RICHARD" : "GABRIEL");
    }
}