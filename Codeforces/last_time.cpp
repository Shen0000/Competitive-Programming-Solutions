#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        deque<pair<int, int> > casinos;
        int l, r, real;
        for (int i=0; i<n; i++) {
            cin >> l >> r >> real;
            casinos.push_back(make_pair(real, l));
        }
        sort(casinos.begin(), casinos.end());
        while (casinos.size()) {
            pair<int, int> next = casinos.front();
            if (k >= next.first) {
                casinos.pop_front();
                continue;
            }
            if (k < next.second) {
                casinos.pop_front();
                continue;
            }
            //
            k = next.first;
            casinos.pop_front();
        }
        cout << k << endl;
    }
}