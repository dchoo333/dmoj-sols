#include <cstdio>

int x[500001], y[500001];

int main() {
    int n, k, s = 0, c = 0;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d %d", x+i, y+i);
    x[n] = k;
    for(int i=0;i<n;i++){
        if(y[i]) continue;
        if(s + x[i] < x[i+1]) s += x[i], c++;
    }
    printf("%d\n%d\n", c, k - (s?s:1));
    return 0;
}