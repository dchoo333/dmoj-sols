#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        int N, M;
        cin >> N >> M;

        vector<string> words(N), lists(M);
        for (int i = 0; i < N; i++) cin >> words[i];
        for (int i = 0; i < M; i++) cin >> lists[i];

        unordered_map<int, vector<int>> bl;
        for (int i = 0; i < N; i++) bl[words[i].size()].push_back(i);

        vector<array<int,26>> pom(N);
        vector<int> lem(N, 0);
        for (int i = 0; i < N; i++) {
            pom[i].fill(0);
            for (int j = 0; j < (int)words[i].size(); j++) {
                int l = words[i][j] - 'a';
                pom[i][l] |= (1 << j);
                lem[i] |= (1 << l);
            }
        }

        cout << "Case #" << cas << ":";

        for (int li = 0; li < M; li++) {
            int lo_idx[26];
            for (int i = 0; i < 26; i++) lo_idx[i] = lists[li][i] - 'a';

            vector<int> scores(N, 0);

            for (auto& [length, group] : bl) {
                int G = group.size();
                if (G == 0) continue;

                int words64 = (G + 63) / 64;

                auto makemask = [&](bool all) -> vector<uint64_t> {
                    vector<uint64_t> v(words64, all ? ~0ULL : 0ULL);
                    if (all && G % 64 != 0)
                        v.back() = (1ULL << (G % 64)) - 1;
                    return v;
                };

                auto band = [&](vector<uint64_t>& a, const vector<uint64_t>& b) {
                    for (int i = 0; i < words64; i++) a[i] &= b[i];
                };

                auto bandnot = [&](vector<uint64_t>& a, const vector<uint64_t>& b) {
                    for (int i = 0; i < words64; i++) a[i] &= ~b[i];
                };

                auto bor = [&](vector<uint64_t>& a, int bit) {
                    a[bit/64] |= (1ULL << (bit%64));
                };

                auto btest = [&](const vector<uint64_t>& a, const vector<uint64_t>& b) -> bool {
                    for (int i = 0; i < words64; i++)
                        if (a[i] & b[i]) return true;
                    return false;
                };

                auto bany = [&](const vector<uint64_t>& a) -> bool {
                    for (auto x : a) if (x) return true;
                    return false;
                };

                vector<vector<uint64_t>> has_l(26, makemask(false));
                for (int g = 0; g < G; g++) {
                    int wi = group[g];
                    int tmp = lem[wi];
                    while (tmp) {
                        int bit = __builtin_ctz(tmp);
                        bor(has_l[bit], g);
                        tmp &= tmp - 1;
                    }
                }

                vector<unordered_map<int, vector<uint64_t>>> pmg(26);
                for (int g = 0; g < G; g++) {
                    int wi = group[g];
                    for (int l = 0; l < 26; l++) {
                        int v = pom[wi][l];
                        auto it = pmg[l].find(v);
                        if (it == pmg[l].end()) {
                            pmg[l][v] = makemask(false);
                            it = pmg[l].find(v);
                        }
                        bor(it->second, g);
                    }
                }

                vector<vector<uint64_t>> can(G, makemask(true));
                vector<int> sgr(G, 0);
                vector<int> gum(G, 0);

                for (int li2 = 0; li2 < 26; li2++) {
                    int l = lo_idx[li2];
                    int lbit = 1 << l;
                    if (!bany(has_l[l])) continue;

                    for (int t = 0; t < G; t++) {
                        if (gum[t] & lbit) continue;
                        if (!btest(can[t], has_l[l])) continue;
                        gum[t] |= lbit;
                        int wi = group[t];
                        if (lem[wi] & lbit) {
                            int v = pom[wi][l];
                            auto it = pmg[l].find(v);
                            if (it != pmg[l].end())
                                band(can[t], it->second);
                            else {
                                fill(can[t].begin(), can[t].end(), 0ULL);
                            }
                        } else {
                            sgr[t]++;
                            bandnot(can[t], has_l[l]);
                        }
                    }
                }

                for (int t = 0; t < G; t++) {
                    scores[group[t]] = sgr[t];
                }
            }

            int bi = 0;
            for (int i = 1; i < N; i++)
                if (scores[i] > scores[bi]) bi = i;

            cout << " " << words[bi];
        }
        cout << "\n";
    }

    return 0;
}
