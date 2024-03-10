#include <iostream>

using namespace std;

int find666(int n){

    int i = 1;
    while(1){
        if(to_string(i).find("666") != -1){     //666이 있으면
            n--;
            if(n==0){       //666이 있는 n번째 수일 때 반환
                return i;       
            }
        }
        i++;
    }
}

int main(){

    int n;
    cin >> n;

    cout << find666(n) << "\n";

    return 0;
}