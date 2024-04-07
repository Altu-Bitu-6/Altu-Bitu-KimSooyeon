#include <iostream>
#include <vector>

using namespace std;

int longest(int n, vector <int> &arr, vector <int> &dp){
    int max_idx = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
            if(dp[i] > dp[max_idx]){
                max_idx = i;
            }
        }
    }
    return max_idx;
}

void increasing(int max_idx, vector <int> &dp, vector <int> &result){
    int temp = dp[max_idx];
    for(int i=max_idx; i>=0; i--){
        if(temp == dp[i]){
            result.push_back(i);
            temp--;
        }
    }
}

int main(){

    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> dp(n,1);
    vector <int> result;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int max_idx = longest(n, arr, dp);
    increasing(max_idx, dp, result);
    
    cout << dp[max_idx] << "\n";

    n = result.size();
    for(int i=n-1; i>=0; i--){
        cout << arr[result[i]] << ' ';
    }
    cout << "\n";

    return 0;
}