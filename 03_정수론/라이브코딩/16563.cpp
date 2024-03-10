#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5000000;    //k의 최대 범위

vector<int> getPrimes(){   
    vector<int> primes(MAX + 1, 0);     //0으로 초기화
    for(int i = 2; i * i <= MAX; i++) {
        if(primes[i] != 0) {    // 소인수로 업데이트 된 경우, 즉 소수가 아닌 경우 탐색하지 않음
            continue;
        }
        
        for(int j = i * i; j <= MAX; j += i) {  //i의 배수 
            if (primes[j] == 0) {   // 소인수로 업데이트 되지 않은 경우만 - 이미 업데이트 되었으면 더 작은 소인수를 가진거니까
                primes[j] = i;      // 소인수로 업데이트
            }
        }
    }
    return primes;
}

vector<int> getPrimeFactors(int k, vector<int> &primes) {
    vector<int> factors;    //소인수 저장

    while(primes[k] != 0) {     //k가 가진 값이 0이 될 때까지 즉 k가 소수일 때까지 역으로 경로 조사
        factors.push_back(primes[k]);
        k /= primes[k];
    }
    factors.push_back(k);
    return factors;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;

    // 50000000까지의 수의 가장 작은 소인수 배열 구함
    vector<int> primes = getPrimes();

    while(n--){
        cin >> k;

        //소인수분해 배열
        vector<int> factors = getPrimeFactors(k, primes);

        //출력
        for (int num : factors) {
            cout << num << " ";
        }
        cout << "\n";

    }

    return 0;
}