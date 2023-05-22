#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;

template <typename T>
void show(const vector<T>& vs) {
    for (auto& v: vs) {
        cout << v << " ";
    }

    cout << "\n";
}

template <typename T>
void load(vector <T>& vs) {
    for (auto& v: vs) {
        cin >> v;
    }
}

void solve() {
    int n;
    cin >> n;

    vector <int> vs(n);
    load(vs);

    long long right = 0, left = vs[0];
    for (int i = 1; i < n; ++i) {
        right += vs[i];
    }

    long long maxGCD = gcd(left, right);
    for (int i = 1; i < n - 1; ++i) {
        left += vs[i];
        right -= vs[i];
        long long g = gcd(left, right);
        if (g > maxGCD) {
            maxGCD = g;
        }
    }

    cout << maxGCD << "\n";
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
