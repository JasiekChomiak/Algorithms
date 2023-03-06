// PROBLEM: https://codeforces.com/contest/1794/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
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

    string s, l1, l2, w;

    for (int i = 0; i < 2 * n - 2; ++i) {
        cin >> s;
        if (s.size() == n - 1) {
            if (l1.empty()) {
                l1 = s;
            } else {
                l2 = s;
            }
        }
    }

    if (n == 2) {
        if (l1 == l2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        return;
    }

    if (l1[0] == l2[1]) {
        w = l2 + l1[n - 2];
    } else {
        w = l1 + l2[n - 2];
    }

    for (int i = 0; i < n / 2; ++i) {
        if (w[i] != w[n - i - 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
