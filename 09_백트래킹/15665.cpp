#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int A[7]; //n 최대 7
int result[7]; // m 최대 7

void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

void backtrack(int cnt){

    if(cnt == m){
        printSequence();
        return;
    }

    //오름차순이니까 전에 고른 수보다 커야 함
    int before = 0; //자연수랬으니까

    for(int i=0; i<n; i++){
        if(before < A[i]){
            result[cnt] = A[i];
            before = A[i];
            backtrack(cnt +1);
        }
    }

}

int main(){

    //입력
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    //오름차순 되도록
    sort(A, A+n);
    
    backtrack(0);
    
    return 0;
}