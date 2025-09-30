#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p) {
            cout << "YES" << endl;
        }
        else {
            cout << (n/p * q == m? "YES": "NO") << endl;
        }
    }
}