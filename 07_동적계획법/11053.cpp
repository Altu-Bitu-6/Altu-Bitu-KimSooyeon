#include <iostream>
#include <vector>

using namespace std;

int longest(int n, vector <int> &arr, vector <int> &dp){
    int max_idx = 0;    // 가장 긴 수열이 될 때의 최댓값을 가리키는 인덱스

    for(int i=1; i<n; i++){     //첫번째 값은 비교할 앞의 값이 없으므로 1부터
        for(int j=0; j<i; j++){     //앞에 주어진 값들에 대해서
            if(arr[j] < arr[i]){    //더 작은 값이 있으면 dp[i]의 값 갱신
                dp[i] = max(dp[i], dp[j]+1); //j로 만들 수 있는 수열에 i 추가할 지
            }
            if(dp[i] > dp[max_idx]){//더 긴 수열이면 max_idx 갱신 
                max_idx = i;
            }
        }
    }
    return max_idx;
}

int main(){

    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> dp(n,1);   //모든 값이 본인을 수열에 가지므로 1로 초기화
    
    //입력
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //연산
    int max_idx = longest(n, arr, dp);

    //출력
    cout << dp[max_idx] << "\n";

    return 0;
}