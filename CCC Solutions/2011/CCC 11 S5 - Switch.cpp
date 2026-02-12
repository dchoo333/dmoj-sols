#include <iostream>
#include <queue>
#include <unordered_map>

int main() {
    int K;
    std::cin >> K;
    int lights[K];
    int state = 0, pow2 = 1;
    for (int i = 0; i < K; i++) {
        std::cin >> lights[i];
        state += pow2 * lights[i];
        pow2 *= 2;
    }

    std::unordered_map<int, int> visited, steps;
    std::queue<int> q;
    q.push(state);
    visited[state] = 1;
    steps[state] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == 0) {
            std::cout << steps[cur] << '\n';
            break;
        }

        int arr[K], backup = cur;
        for (int i = 0; i < K; i++) {
            arr[i] = cur % 2;
            cur /= 2;
        }

        for (int i = K - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i] = 1;
                int l = i, r = i;
                while (l > 0 && arr[l-1] == 1) l--;
                while (r < K-1 && arr[r+1] == 1) r++;
                if (r - l + 1 >= 4)
                    for (int j = l; j <= r; j++) arr[j] = 0;

                int mask = 0, p = 1;
                for (int j = 0; j < K; j++) { mask += arr[j] * p; p *= 2; }

                if (!visited[mask]) {
                    visited[mask] = 1;
                    steps[mask] = steps[backup] + 1;
                    q.push(mask);
                }

                for (int j = l; j <= r; j++) arr[j] = 1;
                arr[i] = 0;
            }
        }
    }
}
