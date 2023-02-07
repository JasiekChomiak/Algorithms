// PROBLEM: https://codeforces.com/contest/1778/problem/B

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> ps(n);
    vector<int> pos(n + 1);
    int p = 1;

    for (auto &v: ps) {
        cin >> v;
        pos[v] = p;
        ++p;
    }

    vector<int> as(m);
    for (auto &v: as) {
        cin >> v;
    }

    int minResult = n + 1;

    for (int i = 0; i < m - 1; ++i) {
        int p1 = pos[as[i]];
        int p2 = pos[as[i + 1]];

        if (!(p1 < p2 && p2 <= p1 + d)) {
            cout << 0 << "\n";
            return;
        }

        int r1 = p2 - p1;
        int maxMove = (p1 - 1) + (n - p2);
        int r2 = p1 + d + 1 - p2;
        if (r2 > maxMove) {
            r2 = n + 1;
        }
        int r = min(r1, r2);

        if (r < minResult) {
            minResult = r;
        }
    }

    cout << minResult << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        solve();
    }

    return 0;
}
