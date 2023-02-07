// PROBLEM: https://codeforces.com/contest/1778/problem/C

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int ones(int n) {
    int r = 0;
    while (n > 0) {
        r += n % 2;
        n /= 2;
    }

    return r;
}

long long calculate(const string& a, const string& b, const set<char>& charSet) {
    long long r = 0, c = 0;

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i] || charSet.find(a[i]) != charSet.end()) {
            ++c;
        } else {
            r += c * (c + 1) / 2;
            c = 0;
        }
    }

    r += c * (c + 1) / 2;

    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    set<char> charSet;
    for (auto c: a) {
        charSet.insert(c);
    }

    if (k > charSet.size()) {
        k = charSet.size();
    }

    vector<char> charVec(charSet.size());
    int j = 0;
    for (auto it = charSet.begin(); it != charSet.end(); ++it) {
        charVec[j] = *it;
        ++j;
    }

    long long maxR = 0;

    for (int i = 0; i < (1 << (charSet.size() + 1)); ++i) {
        if (ones(i) != k) {
            continue;
        }

        set<char> replaceSet;
        int idx = 0, v = i;
        while (v > 0) {
            if (v % 2 == 1) {
                replaceSet.insert(charVec[idx]);
            }

            v /= 2;
            ++idx;
        }

        long long r = calculate(a, b, replaceSet);
        if (r > maxR) {
            maxR = r;
        }
    }

    cout << maxR << "\n";
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
