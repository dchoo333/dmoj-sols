#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        int k;
        cin >> s >> k;

        int n = s.size();
        int ke = min(k, n - 1);

        string stack = "";
        for (char c : s) {
            while (ke > 0 && !stack.empty() && c < stack.back()) {
                stack.pop_back();
                ke--;
            }
            stack.push_back(c);
        }

        if (ke > 0) {
            stack.resize(stack.size() - ke);
        }

        vector<int> fqa(10, 0);
        for (char c : s) {
            fqa[c - '0']++;
        }

        vector<int> freq_kept(10, 0);
        for (char c : stack) {
            freq_kept[c - '0']++;
        }

        string ans = "";
        for (int d = 1; d <= 9; d++) {
            int count = fqa[d] - freq_kept[d];
            ans.append(count, '0' + d);
        }

        cout << stack << ans << '\n';
    }

    return 0;
}
