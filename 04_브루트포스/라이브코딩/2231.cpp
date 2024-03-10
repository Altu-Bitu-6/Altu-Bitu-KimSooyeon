#include <iostream>

using namespace std;


int getGen(int n){
    
    for(int i=0; i<n; i++){

        int sum = i;
        int tmp = i;

        while(tmp){
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == n){
            return i;
        }
    }
    return 0;
}


int main(){
    
    int n;
    cin >> n;

    cout << getGen(n) << "\n";
    
    return 0;
}