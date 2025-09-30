#include <iostream>
#include <vector>

using namespace std;
#define LOG(x) for(auto i:x) cout << i << " "; cout << "\n";
#define all(x) (x).begin(), (x).end()
#define END "\n"
#define SPACE " "

int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int n, m;
    for(int i = 0; i < t; i++){
        int sum = 0;
        int counter = 0;
        vector<int> arr(101);
        arr[0] = 1;
        for (int j = 2; j <= 100; j++){
            arr[j-1] = 8*(j-1);
            
        }

        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> m;
            sum = sum + m;
            while (sum > arr[0]) {
                // cout << "erasing: " << arr[0] << " sum: " << sum << endl;
                sum -= arr[0];
                arr.erase(arr.begin());
            }
            if(sum == arr[0]){
                // cout << "inc counter: " << sum << endl;
                counter++;
                // cout << sum << SPACE;
                sum = 0;
                arr.erase(arr.begin());
                
            }
        }
        cout << counter << END;
        sum = 0;
        counter = 0;

    }
        
    

}