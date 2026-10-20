
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D, c = 0, r;

    cout << "GetN" << endl;
    cin >> N;
    cout << "GetD" << endl;
    cin >> D;

    while (D > 0) {
        cout << "Drop " << min(c + D, N) << endl;
        cin >> r;

        if (r) {
            D--;
            break;
        } else {
            c += D;
            D--;
        }
    }

    while (D > 0) {
        cout << "Drop " << c + 1 << endl;
        cin >> r;

        if (r) break;
        c++;
        D--;
    }

    cout << "Decide " << c + 1 << endl;
    return 0;
}
