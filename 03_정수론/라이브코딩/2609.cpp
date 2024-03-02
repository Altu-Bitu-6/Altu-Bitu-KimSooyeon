#include <iostream>

using namespace std;

int getGCD(int a, int b){   //a와 b의 최대공약수는 a%b와 b의 최대공약수와 같음 
    
    while(b){               //b가 0일 때까지, 다 나누어 떨어져서 a에 최대공약수만 남게 됨
        a %= b;             //a%b 를 구함, b로 나눈 나머지니까 b보다 작은 값이 됨
        swap(a, b);         //a에 큰 값 , b에 작은 값이 오도록 함
    }

    return a;
}

//재귀
int getGCDiter(int a, int b){
    
    if(!b){
        return a;
    }
    
    return getGCDiter(b, a%b);
}


int main(){

    int a, b;
    cin >> a >> b;

    if (a < b){
        swap(a, b);
    }

    //int g = getGCD(a, b);
    int g = getGCDiter(a,b);

    cout << g << '\n' << a * b / g << '\n';     // a * b = 최대공약수 * 최대공배수
    
    return 0;
}