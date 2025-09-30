#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> k >> n;
    vector<int> marks(k), scores(n);
    set<int> intersection;
    for (int i=0; i<k; i++) {
        cin >> marks[i];
    }
    for (int i=0; i<n; i++) {
        cin >> scores[i];
        int curr = scores[i];
        int sum = 0;
        set<int> pos;
        for (int j=0; j<k; j++) {
            sum += marks[j];
            if (i == 0) intersection.insert(curr - sum);
            else if (intersection.count(curr - sum)) pos.insert(curr - sum);
        }
        if (i != 0) intersection = pos;
    }
    cout << intersection.size() << endl;
}