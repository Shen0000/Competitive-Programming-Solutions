// https://codeforces.com/contest/2085/problem/A
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        set<char> unique;
        for (char c: s) unique.insert(c);
        if (k == 0) {
            int index = 0;
            while (index < n && index < n - index - 1 && s[index] == s[n - index - 1]) index++;
            if (s[index] - '0' < s[n - index - 1] - '0') cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            if (unique.size() == 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}