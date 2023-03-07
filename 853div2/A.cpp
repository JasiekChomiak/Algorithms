// PROBLEM: https://codeforces.com/contest/1789/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    for (auto& v: vs) {
        cin >> v;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(vs[i], vs[j]) <= 2) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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
