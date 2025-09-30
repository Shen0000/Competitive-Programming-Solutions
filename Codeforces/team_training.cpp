#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        int cnt = 0;
        int curr = 0;
        int l = 0;
        while (l < n) {
            curr = 1;
            while (l < n && curr * v[l] < k) {
                l++;
                curr++;
            }
            if (l >= n) break;
            if (curr * v[l] >= k) cnt++;
            l++;
        }
        cout << cnt << endl;
    }
}