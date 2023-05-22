// PROBLEM: https://codeforces.com/contest/1790/problem/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const string PI = "314159265358979323846264338327950288419716939937510";

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != PI[i]) {
            cout << i << "\n";
            return;
        }
    }

    cout << s.size() << "\n";
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
