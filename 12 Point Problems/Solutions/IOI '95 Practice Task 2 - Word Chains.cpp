#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string p, w, bw;
    vector<int> st, bs;

    while (cin >> w && w != ".") {
        size_t m = min(p.size(), w.size()), c = 0;
        while (c < m && p[c] == w[c]) c++;
        while (!st.empty() && (size_t)st.back() > c) st.pop_back();
        st.push_back(w.size());
        if (st.size() > bs.size()) bw = w, bs = st;
        swap(p, w);
    }

    string out;
    for (int l : bs) out.append(bw, 0, l), out += '\n';
    fputs(out.c_str(), stdout);
}