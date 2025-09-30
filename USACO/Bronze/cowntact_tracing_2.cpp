#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> components;
    int l = 0, r = 0;
    while (l < n && r < n) {
        if (s[l] == '1') {
            r = l + 1;
            while (r < n && s[r] == '1') {
                r++;
            }
            components.push_back(r - l);
            l = r;
        }
        else l++;
    }
    if (!components.size()) {
        cout << 0 << endl;
        return 0;
    }
    int max_days = 3e5+1;
    for (int i=0; i<components.size(); i++) {
        if (i==0 && s[0] == '1') {
            max_days = min(max_days, components[i]-1);
        }
        else if (i==components.size()-1 && s[n-1] == '1') {
            max_days = min(max_days, components[i]-1);
        }
        else {
            max_days = min(max_days, (components[i]-1)/2);
        }
    }
    // cout << max_days << endl;
    // sort(components.begin(), components.end());
    int ans = 0;
    int span = 2*max_days + 1;
    for (auto c: components) {
        ans += (c-1)/span + 1;
    }
    cout << ans << endl;
}