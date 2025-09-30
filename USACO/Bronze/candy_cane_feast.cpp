#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    for (int i=0; i<m; i++) { // for each candy cane
        ll rem = b[i];
        for (int j=0; j<n; j++) { // simulate for each cow, breaking once the candy cane is fully eaten
            if (a[j] >=b[i] - rem) { // if the cow is tall enough to eat some of the candy cane
                int diff = min(a[j] - (b[i] - rem), rem);
                rem = rem - diff;
                a[j] = a[j] + diff;
            }
            if (rem == 0) break;
        }
    }
    for (int i=0; i<n; i++) {
        cout << a[i] << endl;
    }
}