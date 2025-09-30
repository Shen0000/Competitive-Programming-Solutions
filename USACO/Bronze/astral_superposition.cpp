#include <iostream>
#include <vector>

using namespace std;

bool inbounds(int a, int b, int n) {
    return a < n && b < n && a >= 0 && b >= 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool pos = true;
        int n, a, b, stars = 0;
        cin >> n >> a >> b;
        vector< vector<char> > pic(n, vector<char>(n));
        vector< vector<int> > ref(n, vector<int>(n, 0));
        string line;
        for (int i=0; i<n; i++) {
            cin >> line;
            for (int j=0; j<n; j++) {
                pic[i][j] = line[j];
            }
        }
        for (int i=0; i<n; i++) {
            if (!pos) break;
            for (int j=0; j<n; j++) {
                if (pic[i][j] == 'G') {
                    if (!ref[i][j]) {
                        stars++;
                        if (inbounds(i+b, j+a, n)) ref[i+b][j+a]++;
                    }
                }
                else if (pic[i][j] == 'B') {
                    if (ref[i][j] < 1) {
                        if (inbounds(i-b, j-a, n)) {
                            if (pic[i-b][j-a] == 'G') {
                                stars++;
                                ref[i][j]++;
                            }
                            else if (pic[i-b][j-a] == 'B') {
                                ref[i][j]++;
                            }
                            else {
                                pos = false;
                                break;
                            }
                        }
                        else {
                            pos = false;
                            break;
                        }
                        
                    }
                    stars++;
                    if (inbounds(i+b, j+a, n)) ref[i+b][j+a]++;
                }
            }
        }
        if (!pos) cout << -1 << endl;
        else cout << stars << endl;
    }
}