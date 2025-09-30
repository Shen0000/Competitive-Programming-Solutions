#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x: v) cin >> x;
        set<int> curr, next;
        curr.insert(v[0]);
        int ans = 1;
        int index = 1;
        while (index < n) {
            if (curr.count(v[index])) {
                next.insert(v[index]);
                curr.erase(v[index]);
                if (curr.empty()) {
                    ans++;
                    curr = next;
                    next.clear();
                }
            }
            else next.insert(v[index]);
            index++;
        }
        cout << ans << endl;
    }
}