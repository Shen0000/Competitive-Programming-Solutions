#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    long long comb = 0;
    cin >> n;
    vector<int> v(n), unique(n+1);
    set<int> nums;
    map<int, int> firstOcc;
    map<int, pair<int, int> > lastTwoOcc;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        nums.insert(v[i]);
        unique[i+1] = nums.size(); // one index the unique array for use with the maps later
        if (!firstOcc[v[i]]) firstOcc[v[i]] = i+1;
        lastTwoOcc[v[i]].first = lastTwoOcc[v[i]].second;
        lastTwoOcc[v[i]].second = i + 1;
    }
    for (int x: nums) {
        if (lastTwoOcc[x].first && lastTwoOcc[x].second) {
            // cout << x << " " << lastTwoOcc[x].first << " " << unique[lastTwoOcc[x].first] << endl;
            comb += unique[lastTwoOcc[x].first-1];
            if (firstOcc[x] < lastTwoOcc[x].first) comb--;
        }
    }
    cout << comb << endl;
}