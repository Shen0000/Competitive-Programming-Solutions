#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int l = 0, r = n - 1;
        int ans = 0;
        while (l < r) {
            ans += v[r] - v[l];
            l++;
            r--;
        }
        cout << ans << endl;
    }
}