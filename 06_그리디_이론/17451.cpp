#include <iostream>
#include <vector>

using namespace std;
// 왜자꾸 틀리나 했더니 스피드 범위가 10**9로 크므로 long long으로 선언
typedef long long ll;

//현재 스피드가 필요한 스피드(나중 스피드 later)보다 커야함, 그리고 필요한 스피드의 양의 정수배여야 함
ll bestspeed(int n, vector<ll> &speed){

    ll later = speed[n-1];                     //뒤에서부터 역순으로 확인
    for(int i = n-2; i>=0; i--){
        if(speed[i] < later){           //현재 스피드가 더 작다면
            if(later % speed[i]){       //몫 올림해서 현재스피드에 곱해줌
                speed[i] *= (later/speed[i] + 1);
            }
            else{
                speed[i] *= later/speed[i];
            }
        }
        later = speed[i];
    }
    return later;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> speed (n);
    for(int i=0; i<n; i++){
        cin >> speed[i];
    }
    
    cout <<  bestspeed(n, speed) << "\n";

    return 0;
}