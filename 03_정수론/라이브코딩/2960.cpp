#include <iostream>
#include <vector>

using namespace std;

int findPrime(int n, int k){

    int cnt = 0;
    vector <bool> is_prime(n+1, 1);     //0~n 인덱스 사용하고 싶으므로 길이 n+1
                                        //모두 true로 선언 후 삭제
    for(int i=2; i<=n; i++){
        if(!is_prime[i]){   //이미 삭제된 수 탐색 안 함
            continue;
        }
        for(int j=i; j<=n; j+= i){  //i의 배수면 삭제
            if(!is_prime[j]){
                continue;
            }
            if(++cnt == k){ //k번째 지워지는 수 반환
                return j;
            }
            is_prime[j] = false; 

        }
    }

    return -1;
    
}

int main(){
    int n, k;
    cin >> n >> k;

    int kth = findPrime(n, k);
    cout << kth << '\n';
    
    return 0;
}