#include <iostream>
#include <vector>

using namespace std;

int MAX= -1000000000, MIN = 1000000000, N;
vector <int> OP (4);
vector <int> A (11);  //N 최대 11

void calculate(int result, int idx){

    if(idx == N){
        if(result > MAX){
            MAX = result;
        }
        if(result < MIN){
            MIN = result;
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        if(OP[i] > 0){
            OP[i] -- ;

            if(i == 0){
                calculate(result + A[idx], idx + 1);
            }
            else if(i == 1){
                calculate(result - A[idx], idx + 1);
            }
            else if(i == 2){
                calculate(result * A[idx], idx + 1);
            }
            else {
                calculate(result / A[idx], idx + 1);
            }
            OP[i] ++;
        }
    }
}


int main(){

    //입력
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=0; i<4; i++){
        cin >> OP[i];
    }

    //연산
    calculate(A[0],1);                  //0,1번째 수부터 시작
    cout << MAX << "\n" << MIN << "\n";

    return 0;
}