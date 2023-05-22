// PROBLEM: https://codeforces.com/contest/1789/problem/B
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

    string w;
    cin >> w;

    int s = 0, e = n - 1;
    while (s < e  && w[s] == w[e]) {
        ++s;
        --e;
    }

    // w is a palindrome
    if (s >= e) {
        cout << "YES\n";
        return;
    }

    while (s < e && w[s] != w[e]) {
        ++s;
        --e;
    }

    if (s >= e) {
        cout << "YES\n";
        return;
    }

    while (s < e && w[s] == w[e]) {
        ++s;
        --e;
    }

    if (s >= e) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
