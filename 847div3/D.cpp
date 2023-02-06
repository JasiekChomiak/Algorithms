// PROBLEM: https://codeforces.com/contest/1790/problem/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;

    multiset<int> s;

    int v;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        s.insert(v);
    }

    int result = 0;
    while (!s.empty()) {
        int min = *(s.begin());
        s.erase(s.lower_bound(min));
        while (s.find(min + 1) != s.end()) {
            ++min;
            s.erase(s.lower_bound(min));
        }

        ++result;
    }

    cout << result << "\n";
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
