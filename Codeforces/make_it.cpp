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
        vector<int> h(n);
        for (int &x: h) cin >> x;
        int s = h[k-1];
        sort(h.begin(), h.end());
        int index = 0;
        while (index < n && h[index] < s) index++;
        bool pos = true;
        int water = 1;
        int diff;
        for (int i = index + 1; i<n; i++) {
            diff = h[i] - h[i-1];
            if (diff > h[i-1] + 1 - water) {
                pos = false;
                break;
            }
            water += diff;
        }
        cout << (pos? "YES": "NO") << endl;
    }
}