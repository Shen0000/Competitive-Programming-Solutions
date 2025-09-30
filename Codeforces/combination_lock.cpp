#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (!(n % 2)) {
            cout << -1 << endl;
        }
        else {
            for (int i=n; i>0; i--) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}