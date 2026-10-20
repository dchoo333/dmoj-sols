#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int arr[30001][1001];
int x, y, r, b;
int mv = 0, cm = 0;

int main() {
    scanf("%d%d%d", &M, &N, &K);

    for (int i = 0; i < K; i++) {
        scanf("%d%d%d%d", &x, &y, &r, &b);
        x--; y--;

        for (int j = max(0, x - r); j < min(N, x + r + 1); j++) {
            int dx = abs(x - j);
            int dy = (int)sqrt(r*r - dx*dx);
            int lo = max(0, y - dy);
            int hi = min(M - 1, y + dy);

            arr[lo][j] += b;
            if (hi + 1 < M) arr[hi + 1][j] -= b;
        }
    }

    for (int col = 0; col < N; col++) {
        int curr = 0;
        for (int row = 0; row < M; row++) {
            curr += arr[row][col];
            if (curr > mv) {
                mv = curr;
                cm = 1;
            } else if (curr == mv) {
                cm++;
            }
        }
    }

    printf("%d\n%d\n", mv, cm);
}
