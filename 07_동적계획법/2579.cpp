#include <iostream>
#include <vector>

using namespace std;

void stairs(int n,vector <int> &scores, vector<int> &dp){
    //세번째 앞 계단이 없는 경우들 개별적으로 처리
    dp[1]= scores[1];
    dp[2]= scores[1]+scores[2];
    dp[3]=max(scores[1]+scores[3],scores[2]+scores[3]); 

    //연달아 세계단을 걸을 수 없으므로, 두번째 앞 계단에서 오는 경우 / 3번째 앞과 1번째 앞 계단을 밟고 오는 경우로 나눌 수 있음
    for(int i=4;i<=n;i++){
        dp[i]=max(dp[i-2]+scores[i], dp[i-3]+scores[i-1]+scores[i]);  
    }
}

int main(){
    //입력
    int n;
    cin >> n;

    vector <int> scores (n+1,0);

    for(int i=1; i<=n; i++){
        cin >> scores[i];
    }

    //연산
    vector<int> dp(n+1,0);
    stairs(n, scores, dp);

    //출력
    cout << dp[n] << "\n";

    return  0;
}