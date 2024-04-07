#include <iostream>
#include <vector>

using namespace std;

int fibo_re(int n){
    if(n <= 1){
        return n;
    }
    return fibo_re(n-2) + fibo_re(n-1); 
}

int fibo_dp(int n, vector <int> &result){
    if(n <= 1){
        return n;
    }
    if(result[n]){
        return result[n];
    }
    result[n] = fibo_dp(n-1, result) + fibo_dp(n-2, result);
    return result[n];
}

int main(){

    int n;
    cin >> n;

    vector <int> result(n+1,0);

    cout << fibo_dp(n, result) << "\n";

    return 0;
}