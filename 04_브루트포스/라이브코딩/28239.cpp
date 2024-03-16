#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 60;             //10**18 ~= 2*10*6 60자리 필요

pair <int, int> getPair(ll m){
    int x, y;

    for( ll i = 1; i<MAX; i++){
        if(m == (ll) 1 << i){   //m이 2의 제곱수
            return  pair<int, int>(i - 1, i - 1);
        }
    }

    for (x = 0; x < MAX; x++) {
        if (m & ((ll)1 << x)) {
            m -= (ll)1 << x;
            break;
        }
    }

    for (y = x + 1; y < MAX; y++) {
        if (m & ((ll)1 << y)) {
            break;
        }
    }
    return pair<int, int>(x, y);
}


int main(){

    int n;
    cin >> n;

    ll m;
    while(n--){
        cin >> m;
        pair <int, int> ans = getPair(m);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}