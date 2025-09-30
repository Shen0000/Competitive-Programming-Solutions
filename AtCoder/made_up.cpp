#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    long long ans = 0;
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    for (int i=0; i<n; i++) {
        cin >> c[i];
        mp[b[c[i]-1]]++;
    }
    for (int i=0; i<n; i++) {
        ans += 1ll * mp[a[i]];
    }
    cout << ans << endl;
}