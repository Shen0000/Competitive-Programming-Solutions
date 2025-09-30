#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
using ll = long long;
const int MOD = 998244353;


ll binpow(ll x, ll n, ll m) { // O(log n) time to compute x^n mod m using binary exponentiation
    assert (n>=0);
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }
        int l = 0, r = 0; // two pointers to store indices of the current max valued index at each step of the iteration in both arrays
        for (int i=0; i<n; i++) {
            if (a[i] > a[l]) l = i;
            if (b[i] > b[r]) r = i;
            if (a[l] > b[r]) {
                c[i] = (binpow(2, a[l], MOD) + binpow(2, b[i-l], MOD)) % MOD;
            }
            else if (a[l] < b[r]) {
                c[i] = (binpow(2, b[r], MOD) + binpow(2, a[i-r], MOD)) % MOD;
            }
            else {
                if (a[i-r] > b[i-l]) c[i] = (binpow(2, b[r], MOD) + binpow(2, a[i-r], MOD)) % MOD;
                else c[i] = (binpow(2, a[l], MOD) + binpow(2, b[i-l], MOD)) % MOD;
            }
        }
        for (ll x: c) {
            cout << x << " ";
        }
        cout << endl;
    }
}