#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> v(n);
        int largest = -1;
        for (int &x: v) {
            cin >> x;
            largest = max(largest, x);
        }
        cout << ((k>=2 || (k==1 && largest == v[j-1]))? "YES":"NO") << endl;
    }
}