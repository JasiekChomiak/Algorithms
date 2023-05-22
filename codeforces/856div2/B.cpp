// PROBLEM: https://codeforces.com/contest/1794/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void show(const vector<T>& vs) {
    for (auto v: vs) {
        cout << v << " ";
    }
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;

    vector <int> vs(n);
    for (auto &v: vs) {
        cin >> v;
        if (v == 1) {
            ++v;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (vs[i] % vs[i - 1] == 0) {
            ++vs[i];
        }
    }

    show(vs);
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
