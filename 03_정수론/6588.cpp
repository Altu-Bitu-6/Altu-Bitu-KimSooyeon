#include <iostream>
#include <vector>

using namespace std;

int MAX_SIZE = 1000000;

void findPrime(vector<bool>& is_prime){         //에라토스테네스의 체

    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<=MAX_SIZE;i++){
        if(is_prime[i]){
            for(int j=i*i; j<=MAX_SIZE; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){

    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    //에라토스테네스의 체
    vector <bool> is_prime(MAX_SIZE+1, 1);
    findPrime(is_prime);

    while(true){
        
        cin >> num;
        if(!num || num%2){      //0 입력시 종료, 홀수 입력시 종료
            break;
        }

        int wrong=1;                                        //두 홀수 소수의 합으로 n을 나타낼 수 없는 경우 확인용
        for (int i=2; i<=num/2; i++){                       //num까지 조사하지 않아도 됨
            if(is_prime[i] == 1 && is_prime[num-i] == 1){   //합이 num인 두 수가 모두 소수인 첫번째 경우 출력 - 두 수의 차가 가장 크도록
                cout << num << " = " << i << " + " << num-i << "\n";
                wrong = 0; 
                break;
            }
        }
    
        if(wrong){              
            cout << "Goldbach's conjecture is wrong.";
        }
    }
    
    return 0;
}