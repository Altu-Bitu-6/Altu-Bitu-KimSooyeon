#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> coins (n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        cnt += k / coins[i];
        k = k % coins[i];
    }

    cout << cnt << "\n";

    return 0;
}