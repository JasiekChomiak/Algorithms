// PROBLEM: https://codeforces.com/contest/1778/problem/A

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    bool twoInRow = false, negOne = false;

    int x, last, sum;
    cin >> x;
    last = x;
    sum = x;

    if (x == -1) {
        negOne = true;
    }

    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (x == -1 && last == -1) {
            twoInRow = true;
        } else if (x == -1) {
            negOne = true;
        }

        last = x;
        sum += x;
    }

    if (twoInRow) {
        cout << sum + 4 << "\n";
    } else if (negOne){
        cout << sum << "\n";
    } else {
        cout << sum - 4 << "\n";
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
