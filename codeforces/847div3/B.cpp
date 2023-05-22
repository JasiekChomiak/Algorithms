// PROBLEM: https://codeforces.com/contest/1790/problem/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n, s, r;
    cin >> n >> s >> r;

    int div = r / (n - 1);
    int mod = r % (n - 1);

    for (int i = 0; i < (n - mod - 1); ++i) {
        cout << div << " ";
    }

    for (int i = 0; i < mod; ++i) {
        cout << div + 1 << " ";
    }

    cout << s - r << "\n";
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
