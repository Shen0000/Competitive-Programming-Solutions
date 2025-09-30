#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b; 
        // check all four best first moves and update best according to the minimum resulting answer from each possible first move
        int best = 1 + (int)ceil(log2(a)) + (int)ceil(log2(m)); // cutting the bottom horizontally
        best = min(best, 1 + (int)ceil(log2(n-a+1)) + (int)ceil(log2(m))); // cutting the top horizontally
        best = min(best, 1 + (int)ceil(log2(n)) + (int)ceil(log2(m-b+1))); // cutting the left vertically
        best = min(best, 1 + (int)ceil(log2(n)) + (int)ceil(log2(b))); // cutting the right vertically
        cout << best << endl;
    }
}