#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int f = 0, s = 0;
        int cnt1 = 1, cnt2 = 1;
        if (a[0] != b[0]) {
            cout << "NO" << endl;
            continue;
        }
        bool pos = true;
        vector<int> v1, v2;
        int l = 0, r = 0;
        while (l < a.size()) {
            if (r + 1 == a.size() || a[r+1] != a[r]) {
                v1.push_back(r - l + 1);
                l = r + 1;
                r = l;
            }
            else {
                r++;
            }
        }
        l = 0, r = 0;
        while (l < b.size()) {
            if (r + 1 == b.size() || b[r+1] != b[r]) {
                v2.push_back(r - l + 1);
                l = r + 1;
                r = l;
            }
            else {
                r++;
            }
        }
        if (v1.size() != v2.size()) {
            cout << "NO" << endl;
            continue;
        }
        for (int i=0; i<v1.size(); i++) {
            if (v2[i] > 2 * v1[i] || v2[i] < v1[i]) {
                pos = false;
                break;
            }
        }
        // while (f < a.size() && pos) {
        //     if (f + 1 == a.size() || a[f+1] != a[f]) {
        //         // cout << "f " << f << endl;
        //         cnt2 = 1;
        //         if (s == b.size()) {
        //             pos = false;
        //             break;
        //         }
        //         while (s < b.size() && pos) {
        //             // cout << "s " << s << endl;
        //             if (s + 1 == b.size() || b[s+1] != b[s]) {
        //                 if (cnt2 < cnt1 || cnt2 > 2 * cnt1) {
        //                     pos = false;
        //                 }
        //                 s++;
        //                 break;
        //             }
        //             else {
        //                 cnt2++;
        //                 s++;
        //             }
        //         }
        //         cnt1 = 1;
        //         f++;
        //     }
        //     else {
        //         cnt1++;
        //         f++;
        //     }
        // }
        // if (s < b.size()) pos = false;
        cout << (pos? "YES" : "NO") << endl;
    }
}